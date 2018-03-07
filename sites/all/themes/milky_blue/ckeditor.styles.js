/*
Copyright (c) 2003-2013, CKSource - Frederico Knabben. All rights reserved.
For licensing, see LICENSE.html or http://ckeditor.com/license
*/

/*
 * This file is used/requested by the 'Styles' button.
 * The 'Styles' button is not enabled by default in DrupalFull and DrupalFiltered toolbars.
 */
if(typeof(CKEDITOR) !== 'undefined') {
    CKEDITOR.addStylesSet( 'my_styles',
    [

        { 
                name: 'Normal', 
                element: 'p', 
                attributes: {
                        class: 'normal'
                },
        },

        { 
                name: 'Titre 1', 
                element: 'h1', 
                attributes: {
                        class: 'title1'
                },
        },

        { 
                name: 'Titre 2', 
                element: 'h2', 
                attributes: {
                        class: 'title2'
                },
        },

        { 
                name: 'Titre 3', 
                element: 'h3', 
                attributes: {
                        class: 'title3'
                },
        },
            

    ]);
}