<div id="node-<?php print $node->nid; ?>" class="related <?php print $classes; ?> clearfix"<?php print $attributes; ?> data-link="<?php print $node_link; ?>">
    <?php print render($related_image); ?>
    <?php print render($related_title); ?>
    <?php print $more; ?>
</div>