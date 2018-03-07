(function ($) {
    
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

    var page = 0;
    Drupal.behaviors.MB_projects = {
        attach: function (context, settings) {

          // Article view more click
          $('.view-projects-more-button').once(function(){
            $(this).click(function(){
              console.log('click more');
              console.log('page : ' + page);
              var section = $(this).attr('data-section');
              var count = $(this).attr('data-count');
              console.log('count : ' + count);
              page++;

              //var $projects = $(this).parent().siblings('.view-projects');
              var $content = $('> .view-projects-content', $(this).parent().siblings('.view-projects'));
              var content = $content.html();  
              //console.log('content : ');            
              //console.log(content);            

              var $content_wrapper = $content.closest('.view-projects-wrapper');

              setTimeout(function(){
                throbber('init', 'body');
                $content_wrapper.load('/ajax/projects/' + section + '/' + page + '/' + count, 
                      function(){
                        $('.view-projects-content', $content_wrapper).prepend(content);
                        Drupal.attachBehaviors($(this));
                      });
                
              }, 50);
              $(this).remove();
                      
            });
          });

        },
        detach: function (context, settings) {
            $('.view-projects-more-button').unbind();
        }
      };    
    
    
    
})(jQuery);