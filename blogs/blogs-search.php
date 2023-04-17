<?php
    require 'dbcon.php';

    $query="SELECT * FROM ieraksti2 WHERE status='Aktīvs' AND public='Jā';";
    $result = mysqli_query($con, $query);
    $resultCheck = mysqli_num_rows($result);

    $blogs=[];

    while($row=mysqli_fetch_assoc($result)){
        $row['dateu']=date('d.m.Y.', strtotime($row['date-updated']));
        array_push($blogs, $row);
    }
?>
<?php
include('header.php');
?> 
    <div class="bloga-ieraksti">
        <div id="virsraksts">
            <h1 >Jaunākie bloga ieraksti</h1>
        </div>
            <?php
            include('sidebar.php');
            ?>

            <div  id="content1">

            <?php
                if(isset($_GET['q'])){
                    //search var contains data written in search field
                    $search=mysqli_real_escape_string($con, $_GET['q']);
                    $sql="SELECT * FROM ieraksti2 WHERE title LIKE '%$search%' OR content LIKE '%$search%' OR author LIKE '%$search%' OR `date-created` LIKE '%$search%'";

                    $result=mysqli_query($con, $sql);
                    //check if there is any kind of result
                    $queryResult=mysqli_num_rows($result);

                    if($queryResult > 0){
                        echo "Atrasto rezultātu skaits:  ".$queryResult." ";
                        while($row = mysqli_fetch_assoc($result)){
                            echo "<a href='blog.php?id=".$row['id']."&title=".$row['title']."'>
                            <p>".$row['title']."</p></a>
                            <p class='article'>".mb_substr($row['content'], 0, 200)."</p>";
                        }
                    }else{
                        echo "Nekas netika atrasts!";
                    }
                }
        ?>

        </div>
    </div>
</div>
<?php
include('footer.php');
?>