<?php

function milky_blue_menu_tree__menu_footer_menu($variables) {
	$output = '';
	$output .= '<ul class="menu-footer">';
	$output .= $variables['tree'];
  	$output .= '</ul>';
  	return $output;
}