<?php
$img_uri = $file->uri;
$img_style = 'adaptive';
$img_url = image_style_url($img_style, $img_uri);
$img_alt = render($content['field_file_image_text']);
$img_title = $label;

$thumb = array(
    'style_name' => 'thumbnail',
    'path' => $file->uri,
    'attributes' => array(
        'class' => 'thumbnail',
    ),
);

?>
<div class="slide" style="background-image: url(<?php print $img_url; ?>);" data-alt="<?php print $img_alt; ?>" data-fid="<?php print $file->fid; ?>" data-title="<?php print $img_title; ?>">
<?php print theme('image_style', $thumb); ?>
<?php
global $user;
if ($user->uid) {
print '<div class="edit-wrapper edit-slide">';
print '<a href="/media/' . $file->fid . '/edit/nojs" class="edit">Edit</a>';
print '</div>'; 
}
?>
</div>

