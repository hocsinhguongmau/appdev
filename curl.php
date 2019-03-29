<?php
	$log_file = "testcurl.txt";
	$id = $_POST["ID"];
	$email = $_POST["email"];
	date_default_timezone_get("UTC");
	$str = gmdate("M d Y H:i:s", time()) . " " .$id . " " . $email . "\n";
	echo "This is from the server\n";
	//now we open the file
	if(file_exists($log_file)){
		$fp = fopen($log_file, a); // the file is opened as append mode
		fwrite($fp, $str);
		fclose($fp);
	}else{ //the file doesnt exist, so open a new one
		$fp = fopen($log_file, w); 
		fwrite($fp, $str);
		fclose($fp);
	}
?>