<?php

function milky_blue_menu_link__main_menu($variables) {
  $element = $variables['element'];  
  $element['#localized_options']['attributes']['class'][] = 'main-menu-link';
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  array_push($element['#attributes']['class'], 'main-menu-item');
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . "</li>\n";
}