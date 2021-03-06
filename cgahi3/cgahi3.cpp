/ /   c g a h i 3 . c p p   :   D e f i n e s   t h e   e x p o r t e d   f u n c t i o n s   f o r   t h e   D L L   a p p l i c a t i o n .  
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
 	 c o n s t   i n t   F i l t e r I D   =   0 x 5 D 5 2 ;  
 	 c o n s t   c h a r *   F i l t e r N a m e   =   " C G A   H I - 3 " ;  
 	 c o n s t   c h a r *   F i l t e r D e s c r i p t i o n   =   " C G A   ( M o d e   4 ,   p a l e t t e   2 ,   h i g h   i n t e n s i t y ) " ;  
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
 	 	 	 / /   S E E :     h t t p s : / / e n . w i k i p e d i a . o r g / w i k i / L i s t _ o f _ 8 - b i t _ c o m p u t e r _ h a r d w a r e _ p a l e t t e s # C G A  
 	 	 	 u n s i g n e d   c h a r   G B _ B [ 4 ]   =   {   0 ,   8 5 ,   2 5 5 ,   2 5 5   } ;  
 	 	 	 u n s i g n e d   c h a r   G B _ G [ 4 ]   =   {   0 ,   2 5 5 ,   8 5 ,   2 5 5   } ;  
 	 	 	 u n s i g n e d   c h a r   G B _ R [ 4 ]   =   {   0 ,   2 5 5 ,   8 5 ,   2 5 5   } ;  
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
 
