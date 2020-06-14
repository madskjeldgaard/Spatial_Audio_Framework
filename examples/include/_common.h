/*
 * Copyright 2020 Leo McCormack
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/**
 * @file _common.h
 * @brief A bunch of things that are common to many of the saf examples
 *
 * @author Leo McCormack
 * @date 04.07.2020
 */

#ifndef __COMMON_H_INCLUDED__
#define __COMMON_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
 
/* ========================================================================== */
/*                             Presets + Constants                            */
/* ========================================================================== */

/**
 * Available spherical harmonic (SH) input/output order options
 */
typedef enum _SH_ORDERS{
    SH_ORDER_FIRST = 1, /**< First-order (4 channels) */
    SH_ORDER_SECOND,    /**< Second-order (9 channels) */
    SH_ORDER_THIRD,     /**< Third-order (16 channels) */
    SH_ORDER_FOURTH,    /**< Fourth-order (25 channels) */
    SH_ORDER_FIFTH,     /**< Fifth-order (36 channels) */
    SH_ORDER_SIXTH,     /**< Sixth-order (49 channels) */
    SH_ORDER_SEVENTH    /**< Seventh-order (64 channels) */
    
} SH_ORDERS;
    
/** Maximum supported Ambisonic order */
#define MAX_SH_ORDER ( 7 )
    
/**
 * Available Ambisonic channel ordering conventions
 *
 * @note CH_FUMA only supported for 1st order input.
 */
typedef enum _CH_ORDER {
    CH_ACN = 1, /**< Ambisonic Channel Numbering (ACN) */
    CH_FUMA     /**< (Obsolete) Furse-Malham/B-format (WXYZ) */
    
} CH_ORDER;
    
/** Number of channel ordering options */
#define NUM_CH_ORDERINGS ( 2 )

/**
 * Available Ambisonic normalisation conventions
 *
 * @note NORM_FUMA only supported for 1st order input and does NOT have the
 *       1/sqrt(2) scaling on the omni.
 */
typedef enum _NORM_TYPES {
    NORM_N3D = 1,   /**< orthonormalised (N3D) */
    NORM_SN3D,      /**< Schmidt semi-normalisation (SN3D) */
    NORM_FUMA       /**< (Obsolete) Same as NORM_SN3D for 1st order */
    
} NORM_TYPES;
 
/** Number of normalisation options */
#define NUM_NORM_TYPES ( 3 )

/**
 * Available microphone array presets.
 *
 * These determine the frequency ranges where the microphone array provides
 * usable spherical harmonic components at each order.
 */
typedef enum _MIC_PRESETS{
    MIC_PRESET_IDEAL = 1,
    MIC_PRESET_ZYLIA,
    MIC_PRESET_EIGENMIKE32,
    MIC_PRESET_DTU_MIC

}MIC_PRESETS;

/**
 * Available loudspeaker array presets
 */
typedef enum _LOUDSPEAKER_ARRAY_PRESETS{
    LOUDSPEAKER_ARRAY_PRESET_DEFAULT = 1,
    LOUDSPEAKER_ARRAY_PRESET_STEREO,
    LOUDSPEAKER_ARRAY_PRESET_5PX,
    LOUDSPEAKER_ARRAY_PRESET_7PX,
    LOUDSPEAKER_ARRAY_PRESET_8PX,
    LOUDSPEAKER_ARRAY_PRESET_9PX,
    LOUDSPEAKER_ARRAY_PRESET_10PX,
    LOUDSPEAKER_ARRAY_PRESET_11PX,
    LOUDSPEAKER_ARRAY_PRESET_11PX_7_4,
    LOUDSPEAKER_ARRAY_PRESET_13PX,
    LOUDSPEAKER_ARRAY_PRESET_22PX,
    LOUDSPEAKER_ARRAY_PRESET_AALTO_MCC,
    LOUDSPEAKER_ARRAY_PRESET_AALTO_MCC_SUBSET,
    LOUDSPEAKER_ARRAY_PRESET_AALTO_APAJA,
    LOUDSPEAKER_ARRAY_PRESET_AALTO_LR,
    LOUDSPEAKER_ARRAY_PRESET_DTU_AVIL,
    LOUDSPEAKER_ARRAY_PRESET_ZYLIA_LAB,
    LOUDSPEAKER_ARRAY_PRESET_T_DESIGN_4,
    LOUDSPEAKER_ARRAY_PRESET_T_DESIGN_12,
    LOUDSPEAKER_ARRAY_PRESET_T_DESIGN_24,
    LOUDSPEAKER_ARRAY_PRESET_T_DESIGN_36,
    LOUDSPEAKER_ARRAY_PRESET_T_DESIGN_48,
    LOUDSPEAKER_ARRAY_PRESET_T_DESIGN_60

}LOUDSPEAKER_ARRAY_PRESETS;

/**
 * Available source configurations presets to use for encoding/panning
 */
typedef enum _SOURCE_CONFIG_PRESETS{
    SOURCE_CONFIG_PRESET_DEFAULT = 1,
    SOURCE_CONFIG_PRESET_MONO,
    SOURCE_CONFIG_PRESET_STEREO,
    SOURCE_CONFIG_PRESET_5PX,
    SOURCE_CONFIG_PRESET_7PX,
    SOURCE_CONFIG_PRESET_8PX,
    SOURCE_CONFIG_PRESET_9PX,
    SOURCE_CONFIG_PRESET_10PX,
    SOURCE_CONFIG_PRESET_11PX,
    SOURCE_CONFIG_PRESET_11PX_7_4,
    SOURCE_CONFIG_PRESET_13PX,
    SOURCE_CONFIG_PRESET_22PX,
    SOURCE_CONFIG_PRESET_AALTO_MCC,
    SOURCE_CONFIG_PRESET_AALTO_MCC_SUBSET,
    SOURCE_CONFIG_PRESET_AALTO_APAJA,
    SOURCE_CONFIG_PRESET_AALTO_LR,
    SOURCE_CONFIG_PRESET_DTU_AVIL,
    SOURCE_CONFIG_PRESET_ZYLIA_LAB,
    SOURCE_CONFIG_PRESET_T_DESIGN_4,
    SOURCE_CONFIG_PRESET_T_DESIGN_12,
    SOURCE_CONFIG_PRESET_T_DESIGN_24,
    SOURCE_CONFIG_PRESET_T_DESIGN_36,
    SOURCE_CONFIG_PRESET_T_DESIGN_48,
    SOURCE_CONFIG_PRESET_T_DESIGN_60

}SOURCE_CONFIG_PRESETS;

/**
 * Available static beamforming approaches
 */
typedef enum _STATIC_BEAM_TYPES {
    STATIC_BEAM_TYPE_CARDIOID = 1,  /**< cardioid */
    STATIC_BEAM_TYPE_HYPERCARDIOID, /**< hyper-cardioid */
    STATIC_BEAM_TYPE_MAX_EV         /**< hyper-cardioid with max_rE weighting */

} STATIC_BEAM_TYPES;

/* Number of available static beamformer types */
#define NUM_STATIC_BEAM_TYPES ( 3 )

/**
 * Available horizontal feild-of-view (FOV) options
 */
typedef enum _HFOV_OPTIONS{
    HFOV_360 = 1, /**< 360 degrees */
    HFOV_180,     /**< 180 degrees */
    HFOV_90,      /**< 90 degrees */
    HFOV_60       /**< 60 degrees */

}HFOV_OPTIONS;

/**
 * Available aspect ratios
 */
typedef enum _ASPECT_RATIO_OPTIONS{
    ASPECT_RATIO_2_1 = 1, /**< ASPECT_RATIO_2_1  - 2:1 */
    ASPECT_RATIO_16_9,    /**< ASPECT_RATIO_16_9 - 16:9 */
    ASPECT_RATIO_4_3      /**< ASPECT_RATIO_4_3  - 4:3 */

}ASPECT_RATIO_OPTIONS;
    
/**
 * Current status of the codec.
 */
typedef enum _CODEC_STATUS {
    CODEC_STATUS_INITIALISED = 0, /**< Codec is initialised and ready to process
                                   *   input audio. */
    CODEC_STATUS_NOT_INITIALISED, /**< Codec has not yet been initialised, or
                                   *   the codec configuration has changed.
                                   *   Input audio should not be processed. */
    CODEC_STATUS_INITIALISING     /**< Codec is currently being initialised,
                                   *   input audio should not be processed. */
} CODEC_STATUS;

/**
 * Current status of the processing loop.
 */
typedef enum _PROC_STATUS{
    PROC_STATUS_ONGOING = 0, /**< Codec is processing input audio, and should
                              *   not be reinitialised at this time. */
    PROC_STATUS_NOT_ONGOING  /**< Codec is not processing input audio, and may
                              *   be reinitialised if needed. */
}PROC_STATUS;

/** Length of progress bar string */
#define PROGRESSBARTEXT_CHAR_LENGTH ( 256 )

/** Maximum number of input/output channels supported */
#define MAX_NUM_CHANNELS ( 64 )

/** Maximum number of input channels supported */
#define MAX_NUM_INPUTS ( MAX_NUM_CHANNELS )

/** Maximum number of output channels supported */
#define MAX_NUM_OUTPUTS ( MAX_NUM_CHANNELS )

/** Maximum number of spherical harmonic components/signals supported */
#define MAX_NUM_SH_SIGNALS ( (MAX_SH_ORDER + 1)*(MAX_SH_ORDER + 1) )


#ifdef __cplusplus
} /* extern "C" { */
#endif /* __cplusplus */

#endif /* __COMMON_H_INCLUDED__ */
