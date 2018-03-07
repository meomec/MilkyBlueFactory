<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
$tid = arg(1);
$term = taxonomy_term_load($tid);
?>
<div class="slider-wrapper">
    <?php 
    //print views_embed_view('slider', 'category', $tid); 
    $slider = field_view_field('taxonomy_term', $term, 'field_slides', array('label'=>'hidden', 'type' => 'file_rendered', 'settings' => array('file_view_mode' => 'slide')));
    print render($slider);
    ?>
</div>
<div class="section">
  <div class="<?php print $term->field_machine_name['und'][0]['value'] ?> <?php print $classes; ?> ">
    <?php if ($header): ?>
      <div class="view-header">
        <?php print $header; ?>
      </div>
    <?php endif; ?>

    <?php if ($rows): ?>
      <div class="view-content view-projects-content">
        <?php print $rows; ?>
      </div>
    <?php elseif ($empty): ?>
      <div class="view-empty">
        <?php print $empty; ?>
      </div>
    <?php endif; ?>


  </div>
</div>
