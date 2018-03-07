<header id="header">[header goes here]</header>
<div<?php print $attributes; ?>>
  <div class="l-logo">[logo goes here]</div>
  <div class="burger-menu-wrapper off">
    <div class="burger-menu-close"><?php print t('close menu'); ?></div>
    <?php
      $block_main_menu = module_invoke('menu', 'block_view', 'main-menu');
      print render($block_main_menu['content']);
    ?>
  </div>
  <div class="burger-menu-open">menu</div>
  <!--
  <div class="burger-video off"
    data-vide-bg="mp4: /sites/all/themes/milky_blue/video/video.mp4, webm: /sites/all/themes/milky_blue/video/video.webm, ogv: /sites/all/themes/milky_blue/video/video.ogv, poster: /sites/all/themes/milky_blue/video/video.png"
    data-vide-options="posterType: png, loop: true, muted: true, position: 50% 50%">
  </div>
  -->
  <div class="menu-language-wrapper">
    <?php
    $block = module_invoke('locale', 'block_view', 'language');
    print $block['content'];
    ?>
  </div>
  
  <div class="sticky-menu-wrapper">
    <div class="sticky-menu">
      <?php
      $block_main_menu = module_invoke('menu', 'block_view', 'main-menu');
      print render($block_main_menu['content']);
      ?>
    </div>
  </div>
  <div class="l-main">
    <div class="l-content" role="main">
      <?php print $messages; ?>
      <?php print render($page['content']); ?>
    </div>
  </div>
  <footer class="l-footer" role="contentinfo">
  <?php
      print render($block_main_menu['content']);
    ?>
    <?php
      $block_footer_menu = module_invoke('menu', 'block_view', 'menu-footer-menu');
      print render($block_footer_menu['content']);
    ?>
    <?php
      $block = module_invoke('menu', 'block_view', 'menu-social-menu');
      print render($block['content']);
    ?>
    <?php print render($page['footer']); ?>
    <div class="l-sign">
      <?php
      global $user;
      if ( $user->uid ) {
        print '<a href="/user/logout" class="milky-sign out">sign-out</a>';
      } else {
        print '<a href="/user/login" class="milky-sign in">sign-in</a>';
      }
      ?>      
    </div>
  </footer>

</div>