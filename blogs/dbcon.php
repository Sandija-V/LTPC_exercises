<?php

$hostname="localhost";
$user="root";
$password="pate9gaV!";
$db="blogs";

//izveidojam savienojumu ar datubāzi
$con=mysqli_connect($hostname, $user, $password, $db);

if(!$con){
    die('Kļūda, mēģiniet vēlreiz.' . mysqli_connect_error());
}
