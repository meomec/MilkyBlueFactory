<?php

function milky_blue_links__locale_block(&$variables) {
  // the global $language variable tells you what the current language is
  global $language;

  // an array of list items
  $items = array();
  foreach($variables['links'] as $lang => $info) {

      //print_r($info);
      $short = $info['language']->language; 
      $name = $info['language']->native;
      $href = isset($info['href']) ? $info['href'] : '';
      $li_classes = array('language-item');
      // if the global language is that of this item's language, add the active class
      if($lang === $language->language){
            $li_classes[] = 'active';
      }
      $link_classes = array('language-link');
      $options = array('attributes' => array('class'    => $link_classes),
                                             'language' => $info['language'],
                                             'html'     => true
                                             );
      $link = l($short, $href, $options);
   
      // display only translated links
      if ($href) $items[] = array('data' => $link, 'class' => $li_classes);
    }

  // output
  $attributes = array('class' => array('menu-language'));  
  $output = theme_item_list(array('items' => $items,
                                  'title' => '',
                                  'type'  => 'ul',
                                  'attributes' => $attributes
                                  ));
  return $output;
}