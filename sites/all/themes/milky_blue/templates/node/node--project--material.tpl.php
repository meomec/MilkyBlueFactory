<div id="node-<?php print $node->nid; ?>" class="material <?php print $classes; ?> clearfix"<?php print $attributes; ?> data-link="<?php print $node_link; ?>">
    <h2 class="material-name"><?php print $title; ?></h2>
    <div class="material-image-wrapper">
        <?php print render($material_image); ?>
    </div>
    <!--<div class="box" data-color="<?php print $color; ?>"></div>-->
</div>