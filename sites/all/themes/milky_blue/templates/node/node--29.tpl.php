<?php
// Page materials
$tid = 4;
$term = taxonomy_term_load($tid);
?>
<div id="materials-video-wrapper"><div id="materials-video"></div></div>
<?php print render($title); ?>
<div class="page materials throbber" id="">
    <?php print render($intro); ?>
    <div class="view-projects-wrapper materials naturals">
        <h1 class="title1"><?php print t('Natural & Recycled materials'); ?></h1>
        <?php
        print views_embed_view('materials', 'block', 5);
        ?>
    </div>
    <div class="view-projects-wrapper materials composites">
        <h1 class="title1"><?php print t('Composite materials'); ?></h1>
        <?php
        //milkyblue_ajax_projects('block', 4, 0);
        print views_embed_view('materials', 'block', 7);
        ?>
    </div>
</div>