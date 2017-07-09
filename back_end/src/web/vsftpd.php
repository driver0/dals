<!-- ===========================================================================
// vsftpd.php
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
 
$sql ="select * from vsftpd_log order by time desc;"; 
 
$result = mysql_query($sql,$conn); 
?>

<p style="color:red;font-size:16px;">
vsftpd Log
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


