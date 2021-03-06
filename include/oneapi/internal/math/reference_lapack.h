/* file: reference_lapack.h */
/*******************************************************************************
* Copyright 2014-2020 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/*
//++
//  Wrappers for Lapack functions.
//--
*/

#ifndef __ONEAPI_INTERNAL_MATH_REFERENCE_LAPACK_H__
#define __ONEAPI_INTERNAL_MATH_REFERENCE_LAPACK_H__

#include "types.h"
#include "oneapi/internal/types_utils.h"
#include "services/buffer.h"
#include "services/env_detect.h"

namespace daal
{
namespace oneapi
{
namespace internal
{
namespace math
{
namespace interface1
{
/** @ingroup oneapi_internal
 * @{
 */

/**
 *  <a name="DAAL-CLASS-ONEAPI-INTERNAL__REFERENCEPOTRF"></a>
 *  \brief Adapter for reference POTRF routine
 */
template <typename algorithmFPType>
struct DAAL_EXPORT ReferencePotrf
{
    ReferencePotrf() {}

    services::Status operator()(const math::UpLo uplo, const size_t n, services::Buffer<algorithmFPType> & a_buffer, const size_t lda);
};

/**
 *  <a name="DAAL-CLASS-ONEAPI-INTERNAL__REFERENCEPOTRS"></a>
 *  \brief Adapter for reference POTRS routine
 */
template <typename algorithmFPType>
struct DAAL_EXPORT ReferencePotrs
{
    ReferencePotrs() {}

    services::Status operator()(const math::UpLo uplo, const size_t n, const size_t ny, services::Buffer<algorithmFPType> & a_buffer,
                                const size_t lda, services::Buffer<algorithmFPType> & b_buffer, const size_t ldb);
};

/** @} */
} // namespace interface1

using interface1::ReferencePotrf;
using interface1::ReferencePotrs;

} // namespace math
} // namespace internal
} // namespace oneapi
} // namespace daal

#endif
