<?php
    require 'dbcon.php';
?>

<?php
include('header.php');

$blogId=0;

if(isset($_GET['id'])){
    $blogId=intval($_GET['id']);
}

$query="SELECT * FROM ieraksti2 WHERE id='$blogId';";
$result = mysqli_query($con, $query);
$blogExists = mysqli_num_rows($result);

//if blog exist
$row=mysqli_fetch_assoc($result);
$row['dateu']=date('d.m.Y.', strtotime($row['date-updated']));

?>
    
    <div class="ieraksts">
    <h1 id="virsraksts">Jaunākie bloga ieraksti</h1>

    <?php
        include('sidebar.php');
    ?> 
        

        <div  id="content2">

        <?php
            if($blogExists){

            
        ?>
            <h3><?= $row['title'] ?></h3>
            <h4><?= $row['subtitle'] ?></h4>
            <p><?= $row['author'] ?>,&nbsp;&nbsp;<?= $row['dateu'] ?></p>
            <p class="blogContent"><?= $row['content'] ?></p>
        
        <?php
        }else{
        ?>
            <p>Raksts nav atrasts</p> 
        <?php
        }
        ?>
        </div>
    </div>

<?php
include('footer.php');
?>