<!-- ===========================================================================
// squid3_access.php
//   Copyright (C) 2016 Free Software Foundation, Inc.
//   Originally by ZhaoFeng Liang <zhf.liang@hotmail.com>
//
//This file is part of DTHAS_ALS.
//
//DTHAS_ALS is free software; you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation; either version 2 of the License, or 
//(at your option) any later version.
//
//DTHAS_ALS is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with DTHAS_ALS; If not, see <http://www.gnu.org/licenses/>.  
//=========================================================================== -->

<?php

$mysql_server_name='101.102.103.102'; 
 
$mysql_username='root'; 
 
$mysql_password='root'; 
 
$mysql_database='abc'; 

$conn=mysql_connect($mysql_server_name,$mysql_username,$mysql_password) or die("error connecting") ; 
 
mysql_query("set names 'utf8'");
 
mysql_select_db($mysql_database); 
 
$sql ="select * from squid3_access_log order by time desc;"; 
 
$result = mysql_query($sql,$conn); 
?>

<p style="color:red;font-size:16px;">
squid3_access Log
</p>

<table width="100%" border="1" cellspacing="1" cellpadding="1" borderColor=#000000 style="BORDER-COLLAPSE: collapse">
<?php while($row = mysql_fetch_array($result)) 
{ ?>
	<tr>
	<td>
 		<?php echo $row['time']; ?>
	</td>
	<td>
 		<?php echo $row['ip']; ?>
	</td>
	<td>
 		<?php echo $row['secs']; ?>
	</td>
	<td>
 		<?php echo $row['hit_state_id']; ?>
	</td>
	<td>
 		<?php echo $row['trans_bytes']; ?>
	</td>
	<td>
 		<?php echo $row['req_method']; ?>
	</td>
	<td>
 		<?php echo $row['url']; ?>
	</td>
	<td>
 		<?php echo $row['ident']; ?>
	</td>
	<td>
 		<?php echo $row['code_remoteip']; ?>
	</td>
	<td>
 		<?php echo $row['http_header']; ?>
	</td>	
	</tr>
<?php 
} ?>

</table>


