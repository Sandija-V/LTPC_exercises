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
            <form action="blogs-search.php" method="get">
                <input type="text" name="q" placeholder="Meklēt">
                <button type="submit" name="">Meklēt</button>
            </form>
        </div>
            <?php
            include('sidebar.php');
            ?>

            <div  id="content1">

            <?php
            foreach($blogs as $row){
            ?> 
                <a href="blog.php?id=<?= $row['id']?>"><?= $row['title'] ?></a>
                <p><?= $row['dateu'] ?></p>
                <p class="first200"><?= mb_substr($row['content'], 0, 200) ?></p>
                
            <?php
                }
            ?> 

        </div>
    </div>

<?php
include('footer.php');
?>