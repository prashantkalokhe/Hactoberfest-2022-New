$("#search-icon").click(function() {
    $(".nav").toggleClass("search");
    $(".nav").toggleClass("no-search");
    $(".search-input").toggleClass("search-active");
  });
  
  $('.menu-toggle').click(function(){
     $(".nav").toggleClass("mobile-nav");
     $(this).toggleClass("is-active");
  });
  


  
  $(document).ready(function() {
   var owl = $('.owl-carousel');
   owl.owlCarousel({
       items:4,
       loop:true,
       margin:10,
       autoplay:true,
       autoplayTimeout:1000,
       autoplayHoverPause:true,
       center:true
       
      });
   $('.play').on('click',function(){
       owl.trigger('play.owl.autoplay',[1000])
   })
   $('.stop').on('click',function(){
       owl.trigger('stop.owl.autoplay')
   })



 /*  $(".owl-carousel").owlCarousel({
   
   autoPlay: 3000,
   items : 4,
   itemsDesktop : [1199,3],
   itemsDesktopSmall : [979,3],
   center: true,
   nav:true,
   loop:true,
   responsive: {
   800: {
   items: 2
   }
   }  
   
   });
   */
   });

   