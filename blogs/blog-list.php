<?php
    require 'dbcon.php';

    $query="SELECT * FROM ieraksti2;";
    $result = mysqli_query($con, $query);
    $resultCheck = mysqli_num_rows($result);

    $blogs=[];

    while($row=mysqli_fetch_assoc($result)){
        $row['datec']=date('d.m.Y.', strtotime($row['date-created']));
        $row['dateu']=date('d.m.Y.', strtotime($row['date-updated']));
        array_push($blogs, $row);
    }
    //echo "<pre>";
    //print_r($blogs);
    //echo "</pre>";

    if(isset($_GET["delete"])) {        
        $user_id=intval($_GET['delete']);        
        $query='DELETE FROM ieraksti2 WHERE id="'.$user_id.'"';
        $result=mysqli_query($con, $query);
    }
?>
<?php
include('header.php');
?>

    
    <div class="blog-list">
    <h1 id="virsraksts">Jaunākie bloga ieraksti</h1>

    <?php
    include('sidebar.php');
    ?> 

        <div  id="list">
            <table class="center">
                <tr>
                    <th><a href="?order=title&&sort=$sort">Virsraksts</a></th>
                    <th><a href="?order=author&&sort=$sort">Autors</a></th>
                    <th>Izveidošanas datums</th>
                    <th>Labošanas datums</th>
                    <th>Statuss</th>
                    <th class="option">Darbības</th> 
                </tr>

                <?php
                    foreach($blogs as $row){
            
                ?>
            
                <tr>
                    <td><?= $row['title'] ?></td>
                    <td><?= $row['author'] ?></td>
                    <td><?= $row['datec'] ?></td>
                    <td><?= $row['dateu'] ?></td>
                    <td><?= $row['status'] ?></td>
                    <td><a href="blog-form.php?id=<?=$row['id'] ?>">Rediģēt</a>&nbsp/&nbsp<a href="?delete=<?= $row['id'] ?>">Dzēst</a></td>
                </tr>

                <?php
                }
                ?>
</table>

        </div>
    </div>


<?php
include('footer.php');
?>