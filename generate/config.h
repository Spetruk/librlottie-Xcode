#ifndef CONFIG_H
#define CONFIG_H

#import <TargetConditionals.h>

// disable JSON assert
#define RAPIDJSON_ASSERT

// Threading ENABLED (worker pool, one stroker/outline per worker — thread-safe by design).
// NOTE: do NOT disable LOTTIE_THREAD_SUPPORT: the single-threaded scheduler is a singleton
// with one shared SW_FT_Stroker and no locking, so concurrent renders from different app
// threads corrupt each other's state (border->start = -1 -> EXC_BAD_ACCESS in the stroker).
// The historical OOM blamed on the worker pool actually came from the app eagerly decoding
// every lottie frame at full 512px; with on-demand thumbnail-sized decoding the per-worker
// matte surfaces are small and bounded.
#define LOTTIE_THREAD_SUPPORT

// enable logging
//#define LOTTIE_LOGGING_SUPPORT

// enable module building of image loader
//#define LOTTIE_IMAGE_MODULE_SUPPORT

// enable lottie model caching
//#define LOTTIE_CACHE_SUPPORT

#endif  // CONFIG_H
