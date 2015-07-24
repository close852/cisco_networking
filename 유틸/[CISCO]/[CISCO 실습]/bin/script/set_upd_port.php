<?php

/*******************************************************/
/* Dynamips 辅助工具                                   */
/* 本程序能够自动的更改net目录下所有的拓扑配置文件     */
/* 的Dynamips UDP 端口                                 */
/*                                                     */
/* ver 1.0                                             */
/* Program by Stanely.WY                               */
/*******************************************************/

$dir='../net/';
$udp_port=intval($argv[1]);
$udp_count=0;

if ($udp_port < 1000 || $udp_port >60000 || !$udp_port) {
    echo "\r\nUDP端口号非法!\r\n\r\n";
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

function es_parse_udp_port_str($s,$port) {
    $port=$port+$GLOBALS['udp_count'];
    $p='/^\s*udp(\s)*=(\s)*[0-9]+/';
    if(preg_match($p,$s)) {
        $str=str_replace(substr($s,strrpos($s,'=')+2), $port, $s);
        $GLOBALS['udp_count']+=100;
        return $str."\r\n";
    } else {
        return $s;
    }
}

function es_parse_dir($dir_name) {
	global $udp_port,$udp_count;
	
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
				$var = es_parse_udp_port_str($var, $udp_port);
				$file_content[$key]=$var;
			}
			$contnet = implode("",$file_content);
			$fp = fopen($dir_name.$file_name,'w+');
			fwrite($fp,$contnet);
			fclose($fp);
			echo $dir_name.$file_name."\r\n";
			$GLOBALS['udp_count']=0;
		}
	}
}

if (empty($udp_port) || $udp_port<1 || $udp_port> 65000) {
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
