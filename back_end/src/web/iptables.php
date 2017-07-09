<?php

$mysql_server_name='101.102.103.102'; 
 
$mysql_username='root'; 
 
$mysql_password='root'; 
 
$mysql_database='abc'; 

$conn=mysql_connect($mysql_server_name,$mysql_username,$mysql_password) or die("error connecting") ; 
 
mysql_query("set names 'utf8'"); 
 
mysql_select_db($mysql_database); 
 
$sql ="select * from iptables_log order by time desc;"; 
 
$result = mysql_query($sql,$conn); 
?>

<p style="color:red;font-size:16px;">
iptables Log
</p>

<table width="100%" border="1" cellspacing="1" cellpadding="1" borderColor=#000000 style="BORDER-COLLAPSE: collapse">
<?php while($row = mysql_fetch_array($result)) 
{ ?>
	<tr>
	<td>
 		<?php echo $row['time']; ?>
	</td>
	<td>
 		<?php echo $row['content']; ?>
	</td>	
	</tr>
<?php 
} ?>

</table>


