<?php

/*******************************************************/
/* Dynamips 辅助工具                                   */
/* 本程序能够自动的更改net目录下所有的拓扑配置文件     */
/* 的连接端口                                          */
/*                                                     */
/* ver 3.0                                             */
/* Program by Stanely.WY                               */
/*******************************************************/

$dir='../net/';
$tcp_port=intval($argv[1]);
$tcp_count=1;

if ($tcp_port < 1000 || $tcp_port >60000 || !$tcp_port) {
    echo "\r\nTCP端口号非法!\r\n\r\n";
    die;
}



function es_format_dir_name($dir_name) {
	if (empty($dir_name)) {
		return;
	}
	if (substr($dir_name,strlen($dir_name)-1,strlen($dir_name)) != '/') {
		$dir_name.='/';
	}
	return $dir_name;
}

function es_parse_tcp_port_str($s,$port) {
    $port=$port+$GLOBALS['tcp_count'];
    $p='/^\s*console(\s)*=(\s)*[0-9]+/';
    if(preg_match($p,$s)) {
        $str=str_replace(substr($s,strrpos($s,'=')+2), $port, $s);
        $GLOBALS['tcp_count']++;
        return $str."\r\n";
    } else {
        return $s;
    }
}

function es_parse_dir($dir_name) {
	global $tcp_port,$tcp_count;
	
	$dir_name=es_format_dir_name($dir_name);	
	if (!is_dir($dir_name)) {
		return;
	}
	
	$dh = opendir($dir_name);
	while (false !== ($file_name = readdir($dh))) {
		if ($file_name == '.' || $file_name == '..') {
			continue;
		}
		if (is_dir($dir_name.$file_name)) {
			es_parse_dir($dir_name.$file_name);
		}
				
		$ext_name=substr($file_name,strrpos($file_name,'.')+1,strlen($file_name));
		if ($ext_name == 'net') {
			$file_content = file($dir_name.$file_name);
			foreach ($file_content as $key => $var) {
				$var = es_parse_tcp_port_str($var, $tcp_port);
				$file_content[$key]=$var;
			}
			$contnet = implode("",$file_content);
			$fp = fopen($dir_name.$file_name,'w+');
			fwrite($fp,$contnet);
			fclose($fp);
			echo $dir_name.$file_name."\r\n";
			$GLOBALS['tcp_count']=1;
		}
	}
}

if (empty($tcp_port) || $tcp_port<1 || $tcp_port> 65000) {
	echo "\r\n\r\n";
	echo "┏━━━━━━━━━━━━━━┓\r\n";
	echo "┃错误:端口参数输入不正确!!!  ┃\r\n";
	echo "┗━━━━━━━━━━━━━━┛\r\n";
	echo "\r\n\r\n"; 
} else {
	echo "\r\n\r\n";
	echo "已经成功修改了如下拓扑文件:\r\n";
	es_parse_dir($dir);
	echo "\r\n\r\n";
}

?>
