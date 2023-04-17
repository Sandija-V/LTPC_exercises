<?php
    require 'dbcon.php';
    $id=0;
    if(isset($_GET['id'])){
        $id=intval($_GET['id']);
    }
    if(isset($_POST["save"])) {
        
        $t=$_POST['title'];
        $st=$_POST['subtitle'];
        $a=$_POST['author'];
        $c=$_POST['content'];
        $stat=$_POST['status'];
        if(isset($_POST['public'])){
            $p="Jā";
        }else{
            $p="Nē";
        }           

        $query='INSERT INTO ieraksti2 (id, title, subtitle, author, content, status, public) VALUES ('.$id.',"'.$t.'","'.$st.'", "'.$a.'", "'.$c.'", "'.$stat.'", "'.$p.'") ON DUPLICATE KEY UPDATE title="'.$t.'", subtitle="'.$st.'", author="'.$a.'", content="'.$c.'", status="'.$stat.'", public="'.$p.'", `date-updated`=NOW()';
        $result=mysqli_query($con, $query);

       //echo $query;
    }

    $query='SELECT * FROM ieraksti2 WHERE id='.$id;
    $result=mysqli_query($con, $query);
    $row=mysqli_fetch_assoc($result);

    if($row){        
        $edit_title=$row['title'];
        $edit_subtitle=$row['subtitle'];
        $edit_author=$row['author'];
        $edit_content=$row['content'];	
        $edit_status=$row['status'];
        $edit_public=$row['public'];
    }else{
        $edit_title='';
        $edit_subtitle='';
        $edit_author='';
        $edit_content='';
        $edit_status='';
        $edit_public='';
    }
?>
<?php
include('header.php');
?>
    
    <div class="blog-form">
    <h1 id="virsraksts">Bloga ieraksta detaļas</h1>

    <?php
        include('sidebar.php');
    ?> 

        <div  id="form">
        <form method="post" action="" name="forma">
            <label>Virsraksts</label><br>
                <input type="text" class="input" name="title" value="<?php echo $edit_title; ?>" placeholder="Virsraksts"><br>
            <label>Apakšvirsraksts</label><br>
                <input type="text" class="input" name="subtitle" value="<?php echo $edit_subtitle; ?>" placeholder="Apakšvirsraksts"><br>
            <label>Autors</label><br>
                <input type="text" class="input" name="author" value="<?php echo $edit_author; ?>" placeholder="Autors"><br>
            <label for="">Saturs</label><br>
                <textarea name="content" cols="92" rows="12" placeholder="Saturs" ><?php echo $edit_content; ?>Saturs
            </textarea><br>
        <label for="">Statuss</label><br>
            <select class="input" name="status">
                <option value="">Izvēlies statusu:</option>
                <option value="Aktīvs" <?php if($edit_status=="Aktīvs"){echo "selected";};?>>Aktīvs</option>
                <option value="Neaktīvs" <?php if($edit_status=="Neaktīvs"){echo "selected";};?>>Neaktīvs</option>
            </select> <br>
        <input type="checkbox" name="public" value="Jā" <?php if($edit_public=="Jā"){echo "checked";};?>><label>Publisks?<label><br>
        <!-- <input class="not-public" type="checkbox" name="public" value="Nē"  checked="checked"><br> -->
        <input type="submit" value="Saglabāt" name="save" class="poga">
        </form>
        </div>
    </div>


<?php
include('footer.php');
?>