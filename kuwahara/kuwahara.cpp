/ /   k u w a h a r a . c p p   :   D e f i n e s   t h e   e x p o r t e d   f u n c t i o n s   f o r   t h e   D L L   a p p l i c a t i o n .  
 / /  
  
 # i n c l u d e   " s t d a f x . h "  
  
 # d e f i n e   _ U S E _ M A T H _ D E F I N E S  
 # i n c l u d e   < a l g o r i t h m >  
 # i n c l u d e   < c m a t h >  
 # i n c l u d e   < c s t d l i b >  
 # i n c l u d e   < c s t r i n g >  
  
 # i n c l u d e   " . . / i n c l u d e s / F i l t e r C o m m o n . h "  
  
 # u n d e f   m a x  
  
 e x t e r n   " C "  
 {  
 	 s t a t i c   u n s i g n e d   c h a r *   S c a l e d I m a g e   =   N U L L ;  
  
 	 c o n s t   i n t   F i l t e r I D   =   0 x 5 D 5 8 ;  
 	 c o n s t   c h a r *   F i l t e r N a m e   =   " K u w a h a r a " ;  
 	 c o n s t   c h a r *   F i l t e r D e s c r i p t i o n   =   " A p p l y   K u w a h a r a   F i l t e r " ;  
  
 	 b o o l   C o m p a r i s o n T h r e s h o l d   =   f a l s e ;  
 	 c o n s t   i n t   F i l t e r S c a l e X   =   1 ;  
 	 c o n s t   i n t   F i l t e r S c a l e Y   =   1 ;  
  
 # i n c l u d e   " . . / i n c l u d e s / I n i t . h "  
  
 	 D E C L D I R   i n t   P a r a m e t e r s ( )  
 	 {  
 	 	 / /   N o   S p e c i a l   P a r a m e t e r s  
 	 	 r e t u r n   0 ;  
 	 }  
  
 	 u n s i g n e d   c h a r   C l a m p ( d o u b l e   c )  
 	 {  
 	 	 r e t u r n   ( u n s i g n e d   c h a r ) ( c   <   0   ?   0   :   ( c   >   2 5 5   ?   2 5 5   :   c ) ) ;  
 	 }  
  
 	 v o i d   v a r m i n ( d o u b l e   v a r ,   i n t   s r c x ,   i n t   s r c y ,   d o u b l e &   m i n ,   i n t &   d s t x ,   i n t &   d s t y )  
 	 {  
 	 	 i f   ( v a r   <   m i n )  
 	 	 {  
 	 	 	 m i n   =   v a r ;  
 	 	 	 d s t x   =   s r c x ;  
 	 	 	 d s t y   =   s r c y ;  
 	 	 }  
 	 }  
  
 	 v o i d   K u w a h a r a ( u n s i g n e d   c h a r *   I n p u t ,   i n t   s r c x ,   i n t   s r c y )  
 	 {  
 	 	 i n t   C h a n n e l s   =   3 ;  
  
 	 	 i n t   w i n   =   5 ;  
 	 	 i n t   p a d   =   ( w i n   +   1 )   /   2 ;  
 	 	 i n t   o f s   =   ( w i n   -   1 )   /   2 ;  
 	 	 i n t   f x   =   s r c x   +   o f s ;  
 	 	 i n t   f y   =   s r c y   +   o f s ;  
  
 	 	 a u t o   f x y   =   f x   *   f y ;  
 	 	 d o u b l e *   m e a n   =   n e w   d o u b l e [ f x y ] ;  
 	 	 d o u b l e *   v a r i a n c e   =   n e w   d o u b l e [ f x y ] ;  
  
 	 	 d o u b l e   s u m ,   v a r ;  
 	 	 i n t   n ;  
  
 	 	 f o r   ( i n t   y s   =   - o f s ;   y s   <   s r c y ;   y s + + )  
 	 	 {  
 	 	 	 f o r   ( i n t   x s   =   - o f s ;   x s   <   s r c x ;   x s + + )  
 	 	 	 {  
 	 	 	 	 s u m   =   0 . 0 ;  
 	 	 	 	 v a r   =   0 . 0 ;  
 	 	 	 	 n   =   0 ;  
  
 	 	 	 	 f o r   ( i n t   x f   =   x s ;   x f   <   x s   +   p a d ;   x f + + )  
 	 	 	 	 {  
 	 	 	 	 	 f o r   ( i n t   y f   =   y s ;   y f   <   y s   +   p a d ;   y f + + )  
 	 	 	 	 	 {  
 	 	 	 	 	 	 a u t o   v a l   =   ( d o u b l e ) L u m i n a n c e ( C L R ( I n p u t ,   s r c x ,   s r c y ,   x f ,   y f ) ) ;  
  
 	 	 	 	 	 	 s u m   + =   v a l ;  
 	 	 	 	 	 	 v a r   + =   v a l   *   v a l ;  
  
 	 	 	 	 	 	 n + + ;  
 	 	 	 	 	 }  
 	 	 	 	 }  
  
 	 	 	 	 a u t o   i n d e x   =   ( y s   +   o f s )   *   f x   +   x s   +   o f s ;  
  
 	 	 	 	 m e a n [ i n d e x ]   =   s u m   /   n ;  
 	 	 	 	 v a r i a n c e [ i n d e x ]   =   v a r   -   s u m   *   m e a n [ i n d e x ] ;  
 	 	 	 }  
 	 	 }  
  
 	 	 i n t   x c   =   0 ,   y c   =   0 ;  
  
 	 	 d o u b l e   m i n ;  
  
 	 	 f o r   ( i n t   y   =   0 ;   y   <   s r c y ;   y + + )  
 	 	 {  
 	 	 	 a u t o   y y   =   y   *   s r c x ;  
  
 	 	 	 f o r   ( i n t   x   =   0 ;   x   <   s r c x ;   x + + )  
 	 	 	 {  
 	 	 	 	 m i n   =   s t d : : n u m e r i c _ l i m i t s < d o u b l e > : : m a x ( ) ;  
  
 	 	 	 	 a u t o   y o   =   y   +   o f s ;  
 	 	 	 	 a u t o   x o   =   x   +   o f s ;  
 	 	 	 	 a u t o   y x 1   =   y   *   f x   +   x ;  
 	 	 	 	 a u t o   y x 2   =   y o   *   f x   +   x ;  
  
 	 	 	 	 v a r m i n ( v a r i a n c e [ y x 1 ] ,   x ,   y ,   m i n ,   x c ,   y c ) ;  
 	 	 	 	 v a r m i n ( v a r i a n c e [ y x 2 ] ,   x ,   y o ,   m i n ,   x c ,   y c ) ;  
 	 	 	 	 v a r m i n ( v a r i a n c e [ y x 1   +   o f s ] ,   x o ,   y ,   m i n ,   x c ,   y c ) ;  
 	 	 	 	 v a r m i n ( v a r i a n c e [ y x 2   +   o f s ] ,   x o ,   y o ,   m i n ,   x c ,   y c ) ;  
  
 	 	 	 	 a u t o   d s t   =   ( y y   +   x )   *   C h a n n e l s ;  
  
 	 	 	 	 / /   Y U V   t o   R G B   ( I T U - R )   s e e   h t t p s : / / e n . w i k i p e d i a . o r g / w i k i / Y U V  
 	 	 	 	 a u t o   p i x e l   =   C L R ( I n p u t ,   s r c x ,   s r c y ,   x ,   y ) ;  
  
 	 	 	 	 a u t o   l u m i n a n c e   =   m e a n [ y c   *   f x   +   x c ]   +   0 . 5 ;  
 	 	 	 	 a u t o   c r   =   ( d o u b l e ) C h r o m a U ( p i x e l ) ;  
 	 	 	 	 a u t o   c b   =   ( d o u b l e ) C h r o m a V ( p i x e l ) ;  
 	 	 	 	 a u t o   c r r   =   ( c r   -   1 2 7 . 5 ) ;  
 	 	 	 	 a u t o   c b b   =   ( c b   -   1 2 7 . 5 ) ;  
  
 	 	 	 	 S c a l e d I m a g e [ d s t ]   =   C l a m p ( l u m i n a n c e   +   1 . 0 4 2   *   c r r ) ;  
 	 	 	 	 S c a l e d I m a g e [ d s t   +   1 ]   =   C l a m p ( l u m i n a n c e   -   0 . 3 4 4   *   c b b   -   0 . 7 1 4   *   c r r ) ;  
 	 	 	 	 S c a l e d I m a g e [ d s t   +   2 ]   =   C l a m p ( l u m i n a n c e   +   1 . 7 7 2   *   c b b ) ;  
 	 	 	 }  
 	 	 }  
  
 	 	 d e l e t e [ ]   m e a n ;  
 	 	 d e l e t e [ ]   v a r i a n c e ;  
 	 }  
  
 	 D E C L D I R   v o i d   _ _ s t d c a l l   A p p l y ( i n t   a r g c ,   v o i d * *   a r g v )  
 	 {  
 	 	 i f   ( a r g c   > =   3 )  
 	 	 {  
 	 	 	 a u t o   I n p u t   =   ( ( u n s i g n e d   c h a r * ) ( a r g v [ 0 ] ) ) ;  
 	 	 	 a u t o   s r c x   =   * ( ( i n t * ) ( a r g v [ 1 ] ) ) ;  
 	 	 	 a u t o   s r c y   =   * ( ( i n t * ) ( a r g v [ 2 ] ) ) ;  
  
 	 	 	 I n i t ( s r c x ,   s r c y ) ;  
  
 	 	 	 K u w a h a r a ( I n p u t ,   s r c x ,   s r c y ) ;  
 	 	 }  
 	 }  
 }  
 
