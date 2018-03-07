<?php

function milky_blue_menu_tree__main_menu($variables) {
	$output = '';
	$output .= '<ul class="main-menu">';
	$output .= $variables['tree'];
  	$output .= '</ul>';
  	return $output;
}