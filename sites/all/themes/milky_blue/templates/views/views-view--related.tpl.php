
<div class="<?php print $classes; ?> ">
  <?php if ($rows): ?>
  <h1 class="project-related-bigtitle"><?php print t('See as well');?></h1>
    <div class="view-content view-projects-content">
      <?php print $rows; ?>
    </div>
  <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>
</div>
