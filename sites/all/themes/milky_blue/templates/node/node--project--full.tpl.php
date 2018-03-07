<div id="node-<?php print $node->nid; ?>" class="project <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <h1 class="project-title"><?php print $title; ?></h1>
    <?php print render($project_image_main); ?>
    <div class="project-content-wrapper">
        <h1 class="project-title-again"><?php print $title; ?></h1>
        <div class="project-body">
            <?php print render($project_subtitle); ?>
            <?php print render($content['body']); ?>
        </div>
        <div class="project-images">
            <?php //print render($content['field_images']); ?>
            <?php print $media; ?>
        </div>
    </div>
    <div class="project-related">
        <?php print views_embed_view('related', 'block', $node->nid); ?>
    </div>
</div>
<?php
global $user;
if ( $user->uid ) {
print '<div class="edit-wrapper">';
print '<a href="/node/' . $node->nid . '/edit" class="edit">Edit</a>';
print '</div>'; 
}
?>