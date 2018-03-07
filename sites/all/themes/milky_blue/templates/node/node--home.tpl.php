<div class="slider-wrapper">
    <?php
    //print views_embed_view('slider', 'home'); 
    print render($content['field_slides']);
    ?>
</div>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>
    <div class="section design throbber" id="design">
        <?php print $section_design_intro; ?>
        <div class="view-projects-wrapper design">
            <?php
            milkyblue_ajax_projects('block', 1, 0, 4);
            //print views_embed_view('projects', 'block', 1);
            ?>
        </div>
    </div>

    <hr class="separator" />

    <div class="section art throbber" id="art">
        <?php print $section_art_intro; ?>
        <div class="view-projects-wrapper art">
            <?php
            milkyblue_ajax_projects('block', 2, 0, 4);
            //print views_embed_view('projects', 'block', array(2));
            ?>
        </div>
    </div>

    <hr class="separator" />

    <div class="section restoration throbber" id="restoration">
        <?php print $section_restoration_intro; ?>
        <div class="view-projects-wrapper restoration">
            <?php
            /*
            $block = block_load('block', '2');
            $block_content = _block_render_blocks(array($block));
            $build = _block_get_renderable_array($block_content);
            print render($build);
            */
            milkyblue_ajax_projects('block', 3, 0, 2);
            ?>
        </div>
    </div>

    <hr class="separator" />

    <div class="section materials throbber" id="materials">
        <?php print $section_materials_intro; ?>
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

  </div>
</div>
