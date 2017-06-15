#pragma once

// Macros are usually evil,
// but this is legitimate use because
// we definately want the debug code removed.
// (Also I can't be bothered to mess around with trying
// to get the template equivalent version correct)

#if defined(DEBUG)

  // If in debug mode, use assert functionality
	#if !defined(DEBUG_USE_ASSERT_H)
  
		#define DEBUG_ASSERT(x)
    
	#else defined(DEBUG_USE_ASSERT_H)
  
	#if defined(DEBUG_USE_SERIAL_ASSERT)
		#define __ASSERT_USE_STDERR
	#endif
    
	#include <assert.h>
	#define DEBUG_ASSERT(x) assert(x)
    
#endif

	#if defined(DEBUG_USE_SERIAL_ASSERT)
		void __assert(const char *__func, const char *__file, int __lineno, const char *__sexp)
		{
			// transmit diagnostic informations through serial link. 
			Serial.println(__func);
			Serial.println(__file);
			Serial.println(__lineno, DEC);
			Serial.println(__sexp);
			Serial.flush();
			#if defined(DEBUG_ASSERT_ABORT)
				// abort program execution.
				abort();
			#endif
		}
	#endif
	
#else // Release version

	// Release mode, hide all the debug assertions
	#define DEBUG_ASSERT(x)
	
#endif
