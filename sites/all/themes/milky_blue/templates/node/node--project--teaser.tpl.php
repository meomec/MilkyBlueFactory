<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?> data-link="<?php print $node_link; ?>">
    <?php print render($project_teaser_image); ?>
    <div class="right <?php print $sticky?'narrow':'normal';?>">
        <div class="right-content off">
            <?php print render($teaser_title); ?>
            <?php print render($subtitle); ?>
            <?php print render($body); ?>
            <?php print $more; ?>
        </div>
    </div>
</div>