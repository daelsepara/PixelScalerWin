/ /   d l l m a i n . c p p   :   D e f i n e s   t h e   e n t r y   p o i n t   f o r   t h e   D L L   a p p l i c a t i o n .  
 # i n c l u d e   " s t d a f x . h "  
  
 B O O L   A P I E N T R Y   D l l M a i n (   H M O D U L E   h M o d u l e ,  
                                               D W O R D     u l _ r e a s o n _ f o r _ c a l l ,  
                                               L P V O I D   l p R e s e r v e d  
                                           )  
 {  
         s w i t c h   ( u l _ r e a s o n _ f o r _ c a l l )  
         {  
         c a s e   D L L _ P R O C E S S _ A T T A C H :  
         c a s e   D L L _ T H R E A D _ A T T A C H :  
         c a s e   D L L _ T H R E A D _ D E T A C H :  
         c a s e   D L L _ P R O C E S S _ D E T A C H :  
                 b r e a k ;  
         }  
         r e t u r n   T R U E ;  
 }  
  
 
