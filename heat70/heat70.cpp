/ /   h e a t 7 0 . c p p   :   D e f i n e s   t h e   e x p o r t e d   f u n c t i o n s   f o r   t h e   D L L   a p p l i c a t i o n .  
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
 e x t e r n   " C "  
 {  
 	 s t a t i c   u n s i g n e d   c h a r *   S c a l e d I m a g e   =   N U L L ;  
  
 	 c o n s t   i n t   F i l t e r I D   =   0 x 5 D 4 8 ;  
 	 c o n s t   c h a r *   F i l t e r N a m e   =   " H e a t   ( 7 0   D e g r e e s ,   4 - c o l o r ) " ;  
 	 c o n s t   c h a r *   F i l t e r D e s c r i p t i o n   =   " A p p l y   4 - c o l o r   7 0   d e g r e e s   h e a t   s c h e m e " ;  
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
 	 D E C L D I R   v o i d   _ _ s t d c a l l   A p p l y ( i n t   a r g c ,   v o i d * *   a r g v )  
 	 {  
 	 	 i f   ( a r g c   > =   3 )  
 	 	 {  
 	 	 	 / /   S E E :   h t t p s : / / w w w . s c h e m e c o l o r . c o m / 7 0 - d e g r e e - h e a t - c o l o r s . p h p  
 	 	 	 u n s i g n e d   c h a r   G B _ B [ 4 ]   =   {   2 2 9 ,   2 5 5 ,   2 5 5 ,   2 4 1   } ;  
 	 	 	 u n s i g n e d   c h a r   G B _ G [ 4 ]   =   {   0 ,   1 3 2 ,   2 0 9 ,   2 5 1 } ;  
 	 	 	 u n s i g n e d   c h a r   G B _ R [ 4 ]   =   {   0 ,   3 1 ,   9 8 ,   1 6 6   } ;  
  
 	 	 	 a u t o   I n p u t   =   ( ( u n s i g n e d   c h a r * ) ( a r g v [ 0 ] ) ) ;  
 	 	 	 a u t o   s r c x   =   * ( ( i n t * ) ( a r g v [ 1 ] ) ) ;  
 	 	 	 a u t o   s r c y   =   * ( ( i n t * ) ( a r g v [ 2 ] ) ) ;  
  
 	 	 	 I n i t ( s r c x ,   s r c y ) ;  
  
 	 	 	 a u t o   C h a n n e l s   =   3 ;  
  
 	 	 	 f o r   ( a u t o   y   =   0 ;   y   <   s r c y ;   y + + )  
 	 	 	 {  
 	 	 	 	 f o r   ( a u t o   x   =   0 ;   x   <   s r c x ;   x + + )  
 	 	 	 	 {  
 	 	 	 	 	 a u t o   G   =   L u m i n a n c e ( C L R ( I n p u t ,   s r c x ,   s r c y ,   x ,   y ) ) ;  
 	 	 	 	 	 a u t o   i n d e x   =   ( y   *   s r c x   +   x )   *   C h a n n e l s ;  
 	 	 	 	 	 a u t o   l o o k u p   =   ( i n t ) f l o o r ( G   /   6 4 ) ;  
  
 	 	 	 	 	 S c a l e d I m a g e [ i n d e x ]   =   G B _ R [ l o o k u p ] ;  
 	 	 	 	 	 S c a l e d I m a g e [ i n d e x   +   1 ]   =   G B _ G [ l o o k u p ] ;  
 	 	 	 	 	 S c a l e d I m a g e [ i n d e x   +   2 ]   =   G B _ B [ l o o k u p ] ;  
 	 	 	 	 }  
 	 	 	 }  
 	 	 }  
 	 }  
 }  
  
  
 
