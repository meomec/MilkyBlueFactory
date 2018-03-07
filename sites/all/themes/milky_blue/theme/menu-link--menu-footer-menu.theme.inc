<?php

function milky_blue_menu_link__menu_footer_menu($variables) {
  $element = $variables['element'];
  $element['#localized_options']['attributes']['class'][] = 'menu-footer-link';
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  array_push($element['#attributes']['class'], 'menu-footer-item');
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . "</li>\n";
}