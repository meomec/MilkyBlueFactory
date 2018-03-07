<?php

function milky_blue_menu_tree__menu_social_menu($variables) {
	$output = '';
	$output .= '<ul class="menu-social">';
	$output .= $variables['tree'];
  	$output .= '</ul>';
  	return $output;
}