<?php

function milky_blue_menu_link__menu_social_menu($variables) {
  $element = $variables['element'];
  $element['#localized_options']['attributes']['class'][] = 'menu-social-link';
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  array_push($element['#attributes']['class'], 'menu-social-item');
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . "</li>\n";
}