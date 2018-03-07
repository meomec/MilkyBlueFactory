(function ($) {


  var H = 0;
  var breakpoint = [640, 768, 960, 1280, 1600, 1920, 2400];

  Drupal.behaviors.MB_Contact = {
    attach: function (context, settings) {

      $('.menu-footer-link.contact').click(function(e){
          e.preventDefault();
          e.stopImmediatePropagation();
          $('body').css('overflow', 'hidden');
          $('#contact-wrapper').addClass('on');
          $('#contact-wrapper').addClass('opaque');
          setTimeout(function(){
            $('#contact-wrapper > .contact').addClass('on');
          }, 250);
          
      });

      $('#contact-wrapper .close').click(function(e){
        $('#contact-wrapper > .contact').removeClass('on');
        $('#contact-wrapper').removeClass('opaque');
        $('body').css('overflow', 'auto');
        setTimeout(function(){
          $('#contact-wrapper').removeClass('on');
        }, 250);

        $('#contact-wrapper .close').hover(function(e){
          $(this).addClass('hover');
        }, function(e){
          $(this).removeClass('hover');
        });
        
    });
    },
    detach: function (context, settings) {
      $('.menu-footer-link.contact').unbind();
      $('#contact-wrapper').unbind();
    }
  };

  Drupal.behaviors.MB_Logo = {
    attach: function (context, settings) {
      $('.l-logo')
        .css({'cursor': 'pointer'})
        .click(function(e){
          if (!isHome()) {
            $(location).attr('href', '/');
          }        
        });      
    },
    detach: function (context, settings) {
      $('#logo').unbind();
    }
  };

  Drupal.behaviors.MB_SectionClick = {
    attach: function (context, settings) {
      $('.section_intro')
        .css({'cursor': 'pointer'})
        .click(function(e){
          if (isHome()) {
            href = $(this).attr('data-href');
            $(location).attr('href', href);
          }        
        });      
    },
    detach: function (context, settings) {
      $('#logo').unbind();
    }
  };

  Drupal.behaviors.MB_Material = {
    attach: function (context, settings) {
      $('.material').hover(function(e){  
        console.log('material hover');
        //var $box = $('> .box', this);
        var $title = $('> .material-name', this);
        var $image = $('> .material-image-wrapper > .material-image', this);
        //var box_color = $box.attr('data-color');
        $image.addClass('on');
        setTimeout(function(){  
          $title.addClass('on');  
          /*
          $box
            .css('border-color', box_color)
            .addClass('on');
          */
          $image.addClass('blur');
        }, 10);
        
        
      }, function() {
        console.log('material out');
        //var $box = $('> .box', this);
        var $title = $('> .material-name', this);
        var $image = $('> .material-image-wrapper > .material-image', this);
        //$box.removeClass('on');
        $title.removeClass('on');
        $image.removeClass('on blur');
      });
      $('.material').click(function(e) {
        $(location).attr('href', $(this).attr('data-link'));
      });
    },
    detach: function (context, settings) {
      $('.main-menu-link').unbind();
    }
  };

  Drupal.behaviors.MB_MenuTrigger = {
    attach: function (context, settings) {
      $('.main-menu-link').click(function(e){  
        console.log('click on main-menu-link');
        console.log($(this).attr('href'));
        $('.burger-menu-wrapper.on').removeClass('on').addClass('off');
        setTimeout(function(){
          $('.burger-menu-open').removeClass('off').addClass('on');
        }, 500);
        e.preventDefault();
        e.stopImmediatePropagation();
        var href = $(this).attr('href');
        //filter = href.split('/').pop();
        var filter = $(this).attr('name');
        var $menu = $('.sticky-menu-wrapper');
        var $mobileheader = $('.burger-menu-open');
        var offset = 0;
        if (isMobile()) {
          offset = $mobileheader.outerHeight() * -1;
        } else {
          offset = $menu.outerHeight() * -1;
        }
        console.log('filter : ' + filter);
        if (isHome()) {
          var $target = $('body');
          if (filter != 'home') {
            $target = $('#' + filter);
          }
          MB_scrollTo($target, offset, 1500);
          $('body').css('overflow', 'auto');
          //$('.burger-video').removeClass('on').addClass('off');
        } else {
          window.location = href;
        }
      });

      $('#main-menu-home').click(function(e) {
        if (isHome()) {
          e.preventDefault();
          e.stopImmediatePropagation();         
          
        }
      });

      // hovering menu burger
      var previous_section = '';
      $('.burger-menu-wrapper .main-menu-link').hover(function(e){
        console.log('hover');
        var section = $(this).attr('name');
        /*
        if (section == 'materials') {
          $('.burger-video').removeClass('off').addClass('on');
        } else {
          $('.burger-video').removeClass('on').addClass('off');
        }
        */
        $('.burger-menu-wrapper').removeClass(previous_section).addClass(section);
        previous_section = section;
      }, function(e) {
        console.log('out');
      });

      // open menu
      $('.burger-menu-open').click(function(e) {
        console.log('open menu burger');
        $('.burger-menu-wrapper').removeClass('off materials').addClass('on design');
        $(this).removeClass('on').addClass('off');
        e.preventDefault();
        $('body').css('overflow', 'hidden');
        //$('.burger-menu-wrapper').vide();
      });

      // close menu
      $('.burger-menu-close').click(function(e) {
        $('.burger-menu-wrapper').removeClass('on').addClass('off');
        setTimeout(function(){
          $('.burger-menu-open').removeClass('off').addClass('on');
          e.preventDefault();
          $('body').css('overflow', 'auto');
          //$('.burger-video').removeClass('on').addClass('off');
        }, 500);
      });



    },

    detach: function (context, settings) {
      $('.main-menu-link').unbind();
      $('#main-menu-home').unbind();
      $('.burger-video').unbind();
    }
  };

  Drupal.behaviors.MB_Mores = {
    attach: function (context, settings) {

      $('.node--project--related').hover(function(){
          $('> .project-more', this).addClass('hover');
      }, function() {
        $('> .project-more', this).removeClass('hover');
      });

      $('.project-teaser-title-link').hover(function(){
        $content = $(this).parent().parent();
        $('> .project-more', $content).addClass('hover');
      }, function() {
        $('> .project-more', $content).removeClass('hover');
      });
      
      $('.project-teaser-image-link').hover(function(){
        $content = $(this).siblings();
        $('.project-more', $content).addClass('hover');
      }, function() {
        $('.project-more', $content).removeClass('hover');
      });

    },
    detach: function (context, settings) {
      $('.node--project--related').unbind();
      $('.project-teaser-title-link').unbind();
      $('.project-more').unbind();
    }
  };

  var menu_top_init = 0;
  function stickMenu() {
    if (!isMobile()) {
      var $menu = $('.sticky-menu-wrapper');
      var scrolltop = $(window).scrollTop();
      var menu_top = $menu.position().top;
      //console.log('scrolltop = ' + scrolltop);
      //console.log('menu offset = ' + menu_top);
      if (scrolltop > menu_top) {
        // Sticks menu
        //console.log('sticky');
        $menu.addClass('sticky');
        //console.log('menu_top_init = ' + menu_top_init);
      } 
      else {
        //console.log('not sticky');
        $menu.removeClass('sticky');
      }
      //if (scrolltop <= $(window).height()) {
      if (scrolltop < menu_top_init) {
        //console.log('not sticky');
        $menu.removeClass('sticky');
      }

    }
  }   


  function MB_scrollTo($target, offset, duration) {
    console.log('scrolling to target ' + $target.attr('id'));
    var easing = 'easeOutQuint';
    $(window).scrollTo(
      $target, 
      duration, 
      {
        axis: 'y',
        interrupt: true,
        limit: true,
        offset: offset,
        easing: easing,
        onAfter: function(){
          console.log('scrolled to target done');
        } 
      }
    );
    return false;
  }

  function throbber(param, target) {
    if (typeof target === "undefined" || target === null) { 
      target = 'body'; 
    }
    console.log('throbber on : ' + target)
    if(param == 'init') {
      $(target).prepend('<div id="ajax_throbber_wrapper"><div id="ajax_throbber_inner"><div class="ajax_throbber animate-spin"></div></div></div>');
    } else if (param == 'destroy') {
      $('#ajax_throbber_wrapper').remove();
    }
  }

  function isHome() {
    return $('body.front').length;
  } 

  function isMobile() {
    return $(window).width() <= breakpoint[0];
  }


  function MilkyBlue_initSlider() {
    var $slick = $('.slider-items');
    $slick.on('init', function(event, slick, currentSlide){}); 
    $slick.slick({
      'centerMode': false,
      'centerPadding': '100px',
      'variableWidth': false,
      'initialSlide': 0,
      'infinite': true,
      'lazyLoad': 'ondemand',
      'lazyLoadBuffer': 0,
      'fade': false,
      'cssEase': 'linear',
      'accessibility': true,      
      'arrows': false,
      'dots': false,
      'dotsClass': 'slick-dots',
      'mobileFirst': true,
      'autoplay': true,
      'autoplaySpeed': 7000,
      'speed': 350,
      'pauseOnFocus': false,
      'pauseOnHover': false,
      'pauseOnDotsHover': false,
      'responsive': [
        {
          'breakpoint': breakpoint[1],
          'settings': {
            'fade': true,
            'dots': true,
          }
        },
        {
          'breakpoint': breakpoint[0],
          'settings': {
            'fade': false,
          }
        }
        // You can unslick at a given breakpoint now by adding:
        // settings: "unslick"
        // instead of a settings object
      ]
    });
    $slick.on('afterChange', function(event, slick, currentSlide){});  
    $slick.on('beforeChange', function(event, slick, currentSlide){});     
  }  


  function hackHTML() {

    var $menu = $('.sticky-menu-wrapper');
    var menu_top = $menu.position().top;
    menu_top_init = menu_top;

    // Middle center project teaser right content
    //if (isMobile()) {
      $('.project-teaser-image').each(function() {
        var h = $(this).height();
        var $gdparent = $(this).parent().parent();
        $('> .right', $gdparent).css('min-height', h);
      });
    //}
    

    // Turn project teaser right content on
    $('.right-content.off').each(function(){
      $(this).removeClass('off').addClass('on');
    });

    // Hack material dimension
    $('.material').each(function(){
      w = $(this).width();
      $(this).css('height', w);
    });

    // Display project page title
    setTimeout(function(){
      $('.project-title').show();
    $('.materials-title').show();
    }, 250);
    /*
    $('.project-image-main').load(function(){
      console.log('project image loaded');
      $('.project-title').addClass('on');
    });
    */
  

  }

  function ready(){
    Drupal.attachBehaviors(document);  
    MilkyBlue_initSlider();


    
    $('#materials .section_intro, #materials-video').vide({
      mp4: '/sites/all/themes/milky_blue/video/milky.mp4',
      webm: '/sites/all/themes/milky_blue/video/milky.webmhd.webm',
      ogv: '/sites/all/themes/milky_blue/video/milky.oggtheora.ogv',
      poster: '/sites/all/themes/milky_blue/video/560153144.webmhd.png'
    }, {
      volume: 0,
      playbackRate: 1,
      muted: true,
      loop: true,
      autoplay: true,
      position: '50% 50%', // Similar to the CSS `background-position` property.
      posterType: 'png', // Poster image type. "detect" — auto-detection; "none" — no poster; "jpg", "png", "gif",... - extensions.
      resizing: true, // Auto-resizing, read: https://github.com/VodkaBears/Vide#resizing
      bgColor: 'transparent', // Allow custom background-color for Vide div,
      className: '' // Add custom CSS class to Vide div
    });
    
    $('.media-youtube-video').fitVids();
    
    $('body').fitVids({
      customSelector: 'iframe[src*="facebook"]'
    });


    if (isMobile()) {
      $('header').headroom(
        {
            // vertical offset in px before element is first unpinned
            // offset : 0,
            // scroll tolerance in px before state changes
            // tolerance : 0,
            // or you can specify tolerance individually for up/down scroll
            tolerance : {
                up : 10,
                down : 10
            },
            // css classes to apply
            classes : {
                // when element is initialised
                initial : "headroom",
                // when scrolling up
                pinned : "pinned",
                // when scrolling down
                unpinned : "unpinned",
                // when above offset
                top : "top",
                // when below offset
                notTop : "not-top"
            },
            // element to listen to scroll events on, defaults to `window`
            scroller : window,
            // callback when pinned, `this` is headroom object
            onPin : function() {console.log('header down');},
            // callback when unpinned, `this` is headroom object
            onUnpin : function() {console.log('header up');},
            // callback when above offset, `this` is headroom object
            onTop : function() {console.log('header top');},
            // callback when below offset, `this` is headroom object
            onNotTop : function() {console.log('header not top');},
        }
      );
      $('.burger-menu-open').clone().appendTo('#header');
      Drupal.attachBehaviors($('.burger-menu-open'));
    }
    
    


  }

  function loaded(){
    hackHTML();
  }

  function resize(){
    hackHTML();
  }

  function scroll() {
    stickMenu();
  }

  function ajaxSuccess(event,xhr,options) {
    //ajax_data = xhr.responseJSON;
    //console.log(ajax_data);
    setTimeout(function(){
      throbber('destroy');
      hackHTML();
      //DD_initBrands(); 
    }, 3000);
  }


  $(window).ready(ready);
  $(window).load(loaded);
  $(window).scroll(scroll);
  $(window).resize(resize);
  $(window).ajaxSuccess(function (event,xhr,options) {
    console.log('Ajax Success'); 
    ajaxSuccess(event,xhr,options);
  }); 

})(jQuery);
