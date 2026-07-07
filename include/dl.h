/***************************************************
 * FILENAME :		dl.h
 * 
 * DESCRIPTION :
 * 		
 * 		
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */

#ifndef _LIBRAC4_DL_H_
#define _LIBRAC4_DL_H_

/*
 * NAME :		dlPreUpdate
 * 
 * DESCRIPTION :
 * 			Must be called at the beginning of each tick.
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
void dlPreUpdate(void);

/*
 * NAME :		dlPostUpdate
 * 
 * DESCRIPTION :
 * 			Must be called at the end of each tick.
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
void dlPostUpdate(void);

#endif // _LIBRAC4_DL_H_
