<?php



function milky_blue_section_intro($tid, $variable_srt) {
    global $language ;
    $lang_name = $language->language;
    $current_lang = $lang_name;
    $lang = $lang_name;

    $term = taxonomy_term_load($tid);
    $translated_term = i18n_taxonomy_localize_terms($term);
    $cat_machine_value = field_get_items('taxonomy_term', $term, 'field_machine_name', $lang);
    $cat_machine_name = $cat_machine_value[0]['value'];
    if ($tid == 4 || $tid == 5 || $tid == 7) {
        // Materials
        $cat_url = $lang . '/' . 'matériauthèque';    
    } else {
        $cat_url = $lang . '/' . drupal_lookup_path('alias', 'projects/' . $tid);
    }
    
    // Teaser
    $teaser = field_view_field('taxonomy_term', $translated_term, 'field_body', array(
        'label'=>'hidden', 
        'type' => 'text_summary_or_trimmed', 
        'settings' => array('trim_length' => 200),
    ));
    return $variables[$variable_srt] = '<div class="section_intro ' . $cat_machine_name . '" data-href="/' . $cat_url . '"><h1 class="title1">' . $translated_term->name . '</h1><div class="intro">' . render($teaser) . '</div></div>';
}

function milky_blue_preprocess_node(&$variables) {
    
    global $language ;
    $lang_name = $language->language;
    $current_lang = $lang_name;
    $lang = $lang_name;
    

    $node = $variables['node'];
	$node_type = $node->type;
	$node_nid = $node->nid;
    $view_mode = $variables['view_mode'];
    
    // node url
    $node_url = drupal_get_path_alias('node/' . $node->nid, $lang_name);
    $node_link = url($node_url, array('absolute' => FALSE));
    $variables['node_link'] = $node_link;


    $variables['color'] = '';
    
    if ($node_type == 'home') {

        // Load sections title & introduction
        // Design
        $variables['section_design_intro'] = milky_blue_section_intro(1, 'section_design_intro');
        // Art
        $variables['section_art_intro'] = milky_blue_section_intro(2, 'section_art_intro');
        // Restoration
        $variables['section_restoration_intro'] = milky_blue_section_intro(3, 'section_restoration_intro');
        // Materials
        $variables['section_materials_intro'] = milky_blue_section_intro(4, 'section_materials_intro');


    } elseif ($node_type == 'project') {


        // More
        
        $cat_tid = -1;    
        $cat_name = '';
        $cat_machine_name = '';  
        /*
        print '<pre>';
        print_r($node->field_typology);
        print '</pre>';
        */
        if (isset($node->field_typology[$lang])) {
            $cat_tid = $node->field_typology[$lang][0]['target_id'];    
            $cat_term = taxonomy_term_load($cat_tid);
            $cat_value = field_get_items('taxonomy_term', $cat_term, 'name_field', $lang);
            $cat_name = $cat_value[0]['value'];
            $cat_machine_value = field_get_items('taxonomy_term', $cat_term, 'field_machine_name', $lang);
            $cat_machine_name = $cat_machine_value[0]['value'];
        }
        
        $variables['more'] = l(
            t('read full content'),
            $node_url,
            array(
                'attributes' => array(
                    'class' => array('project-more', $cat_machine_name),
                ),
                'html' => false,
            )
        );

        if ($view_mode == 'teaser') {

            // Title
            $teaser_title = array(
                '#type' => 'html_tag',
                '#tag' => 'h2',
                '#attributes' => array(
                    'class' => array('project-teaser-title', $cat_name),
                ),
                '#value' => l($node->title, $node_url, array('attributes' => array('class' => array('class' => $cat_name, 'project-teaser-title-link')))),
            );
            $variables['teaser_title'] = $teaser_title;

            // Image
            $img_uri = $node->field_image['und'][0]['uri'];
            // load picture mapping
            $picture_mapping = picture_mapping_load('milky_blue_half_crop');
            // load breakpoints
            $fallback = 'thumbnail';
            $breakpoints = picture_get_mapping_breakpoints($picture_mapping, $fallback); 
            // theme image
            $image = array(
                '#type' => 'html_tag',
                '#tag' => 'div',
                '#attributes' => array(
                    'class' => array(
                        'project-teaser-image',
                        $variables['sticky']?'large':'normal',
                    ),
                ),
                '#value' => theme(
                                'picture', 
                                array(
                                    'uri' => $img_uri, 
                                    'style_name' => $fallback, 
                                    'breakpoints' => $breakpoints, 
                                    'attributes' => array(
                                        'class' => $variables['sticky']?'large':'normal',
                                    )
                                )
                            ),
            );
            $image_link = array(
                '#type' => 'html_tag',
                '#tag' => 'a',
                '#attributes' => array(
                    'href' => $node_link,
                    'class' => 'project-teaser-image-link',
                ),
                '#value' => render($image)
            );
            $variables['project_teaser_image'] = $image_link;

            // Teaser
            $body = field_view_field('node', $node, 'body', array(
                'label'=>'hidden', 
                'type' => 'text_summary_or_trimmed', 
                'settings' => array('trim_length' => 200),
            ));
            $subtitle_value = $node->field_subtitle[$lang][0]['value'];
            $subtitle = array(
                '#type' => 'html_tag',
                '#tag' => 'h3',
                '#attributes' => array(
                    'class' => array('project-teaser-subtitle', $subtitle_value),
                ),
                '#value' => $subtitle_value,
            );
            $variables['body'] = $body;
            $variables['subtitle'] = $subtitle;
        } elseif ($view_mode == 'material') {
            // Image
            $img_uri = $node->field_image['und'][0]['uri'];
            $img_style = '400x400';
            $img_url = image_style_url($img_style, $img_uri);
            $img_style = 'background-image: url(' . $img_url . ');';
            $img = array(
                '#type' => 'html_tag',
                '#tag' => 'div',
                '#attributes' => array(
                    'class' => 'material-image',
                    'style' => $img_style,
                ),
                '#value' => '',
            );
            $variables['material_image'] = $img;

            // Color
            if (isset($node->field_color['und'])) {
                $color = $node->field_color['und'][0]['rgb'];
                $variables['color'] = $color;
            }

        } elseif ($view_mode == 'related') {
            // Image
            $img_uri = $node->field_image['und'][0]['uri'];
            // load picture mapping
            $picture_mapping = picture_mapping_load('related');
            // load breakpoints
            $fallback = 'thumbnail';
            $breakpoints = picture_get_mapping_breakpoints($picture_mapping, $fallback); 
            // theme image
            $image = array(
                '#type' => 'html_tag',
                '#tag' => 'div',
                '#attributes' => array(
                    'class' => array(
                        'related-image-wrapper',
                    ),
                ),
                '#value' => theme(
                                'picture', 
                                array(
                                    'uri' => $img_uri, 
                                    'style_name' => $fallback, 
                                    'breakpoints' => $breakpoints, 
                                    'attributes' => array(
                                        'class' => array('related-image'),
                                    )
                                )
                            ),
            );	
            $image_link = array(
                '#type' => 'html_tag',
                '#tag' => 'a',
                '#attributes' => array(
                    'href' => $node_link,
                    'class' => '',
                ),
                '#value' => render($image)
            );
            $variables['related_image'] = $image_link;

            // Title
            // See above
            
            if ($cat_tid == 4) {
                // Materials
                $cat_url = '/materials';    
            } else {
                //$cat_url = drupal_lookup_path('alias', 'taxonomy/term/'. $cat_tid);
                $cat_url = '/' . $lang . '/projects/' . $cat_tid;    
            }
            $cat_html = array(
                '#type' => 'html_tag',
                '#tag' => 'a',
                '#attributes' => array(
                    'class' => 'related-category',
                    'href' => $cat_url,
                ),
                '#value' => $cat_name
            );
            $title_html = array(
                '#type' => 'html_tag',
                '#tag' => 'a',
                '#attributes' => array(
                    'class' => 'related-title',
                    'href' => $node_link
                ),
                '#value' => $node->title
            );

            $related_title = array(
                '#type' => 'html_tag',
                '#tag' => 'div',
                '#attributes' => array(
                    'class' => 'related-title-wrapper',
                ),
                '#value' => render($title_html) . render($cat_html),
            );
            $variables['related_title'] = $related_title;

        } elseif ($view_mode == 'full') {


            // Image
            $img_uri = $node->field_image['und'][0]['uri'];
            $img_style = 'adaptive';
            $img_url = image_style_url($img_style, $img_uri);
            $project_image_main_style = 'background-image: url(' . $img_url . ');';
            $project_image_main = array(
                '#type' => 'html_tag',
                '#tag' => 'div',
                '#attributes' => array(
                    'class' => 'project-image-main',
                    'style' => $project_image_main_style,
                ),
                '#value' => '',
            );
            $variables['project_image_main'] = $project_image_main;


            // Images - media
            $picture_mapping = picture_mapping_load('milky_blue_half');
            $fallback = 'thumbnail';
            $breakpoints = picture_get_mapping_breakpoints($picture_mapping, $fallback); 
            $output = '';
            if (isset($node->field_images['und'])) {
                foreach ($node->field_images['und'] as $obj) {
                    /*
                    print '<pre>';
                    print_r ($obj);
                    print '</pre>';
                    */
                    $fid = $obj['fid'];
                    $img_type = $obj['type'];
                    $img_filemime = $obj['filemime'];
                    $img_uri = $obj['uri'];
    
                    $file = file_load($fid); // Load the file with the specified ID.
                    $build = file_view($file); // Build a render array from the loaded file.
                    
                    $caption = '';
                    if (isset($obj['field_caption']['und'])) {
                        $caption = array(
                            '#type' => 'html_tag',
                            '#tag' => 'div',
                            '#attributes' => array(
                                'class' => array(
                                    'project-image-caption',
                                ),
                            ),
                            '#value' => $obj['field_caption']['und'][0]['value'],
                        );
                    }
                    
                    $media = array(
                        '#type' => 'html_tag',
                        '#tag' => 'div',
                        '#attributes' => array(
                            'class' => array(
                                'project-media-wrapper',
                            ),
                        ),
                        '#value' => drupal_render($caption) . drupal_render($build) // Render the array and print out the resulting HTML.
                    );
    
                    $output .= render($media);
    
                    /*
                    if ($img_filemime == 'image/jpeg') {
                        $image = array(
                            '#type' => 'html_tag',
                            '#tag' => 'div',
                            '#attributes' => array(
                                'class' => array(
                                    'project-image-wrapper',
                                ),
                            ),
                            '#value' => theme(
                                            'picture', 
                                            array(
                                                'uri' => $img_uri, 
                                                'style_name' => $fallback, 
                                                'breakpoints' => $breakpoints, 
                                                'attributes' => array(
                                                    'class' => array('project-image'),
                                                    'alt' => isset($obj['field_file_image_alt_text']['und'])?$obj['field_file_image_alt_text']['und'][0]['value']:'Milky Blue Factory',
                                                    'title' => isset($obj['field_file_image_title_text']['und'])?$obj['field_file_image_title_text']['und'][0]['value']:'Milky Blue Factory',
                                                )
                                            )
                                        ),
                        );
                        $output .= render($image);
                    }
                    elseif ($img_type == 'video' && $img_filemime == 'video/youtube') {
                        $file = file_load($fid); // Load the file with the specified ID.
                        $build = file_view($file); // Build a render array from the loaded file.
                        $output .= drupal_render($build); // Render the array and print out the resulting HTML.
                    }
                    */
                        
                }
            }
            $variables['media'] = $output;


            // Subtitle
            if ($cat_tid == 4 || $cat_tid == 5 || $cat_tid == 7) {
                // Materials
                $cat_url = 'matériauthèque';    
            } else {
                
                //$cat_url = '/' . $lang . '/projects/' . $cat_tid;    
                $cat_url = drupal_lookup_path('alias', 'projects/' . $cat_tid);
            }
            $cat_html = array(
                '#type' => 'html_tag',
                '#tag' => 'a',
                '#attributes' => array(
                    'class' => 'project-category',
                    'href' => '/' . $lang . '/' . $cat_url,
                ),
                '#value' => $cat_name
            );
            
            $subtitle_value = $node->field_subtitle[$lang][0]['value'];
            $subtitle_html = array(
                '#type' => 'html_tag',
                '#tag' => 'h2',
                '#attributes' => array(
                    'class' => 'project-subtitle',
                ),
                '#value' => $subtitle_value
            );

            $project_subtitle = array(
                '#type' => 'html_tag',
                '#tag' => 'div',
                '#attributes' => array(
                    'class' => 'project-subtitle-wrapper',
                ),
                '#value' => render($subtitle_html) . render($cat_html),
            );
            $variables['project_subtitle'] = $project_subtitle;




        }

        



    }


    // Node materials
    if ($node->nid == 29) {
        // Materials
        $variables['section_materials_intro'] = milky_blue_section_intro(4, 'section_materials_intro');
        $tid = 4;
        $term = taxonomy_term_load($tid);
        $translated_term = i18n_taxonomy_localize_terms($term);
        $variables['title'] = array(
            '#type' => 'html_tag',
                '#tag' => 'h1',
                '#attributes' => array(
                    'class' => array('materials-title'),
                ),
                '#value' => $translated_term->name
        );
        $term_field_body = field_get_items('taxonomy_term', $term, 'field_body');
        $intro = array(
            '#type' => 'html_tag',
                '#tag' => 'div',
                '#attributes' => array(
                    'class' => array('intro'),
                ),
                '#value' => $term_field_body[0]['value']
        );
        $variables['intro'] = array(
            '#type' => 'html_tag',
                '#tag' => 'div',
                '#attributes' => array(
                    'class' => array('section_intro'),
                ),
                '#value' => render($intro)
        );
        
        

    }
}

?>