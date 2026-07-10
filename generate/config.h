#ifndef CONFIG_H
#define CONFIG_H

#import <TargetConditionals.h>

// disable JSON assert
#define RAPIDJSON_ASSERT

// threading DELIBERATELY disabled.
// With LOTTIE_THREAD_SUPPORT enabled, rlottie renders each animation across a pool of worker
// threads, and every thread allocates its own ~512x512 (1 MB) intermediate surface for
// matte/mask layers (SurfaceCache::make_surface -> VBitmap). When many animated stickers render
// at once, those simultaneous 1 MB allocations blow the process memory limit and throw
// std::bad_alloc (NSMallocException). Single-threaded rendering allocates matte surfaces one at
// a time instead of ~16 at once, which keeps peak memory bounded.
// #define LOTTIE_THREAD_SUPPORT

// enable logging
//#define LOTTIE_LOGGING_SUPPORT

// enable module building of image loader
//#define LOTTIE_IMAGE_MODULE_SUPPORT

// enable lottie model caching
//#define LOTTIE_CACHE_SUPPORT

#endif  // CONFIG_H
