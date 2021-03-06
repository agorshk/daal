/* file: pca_dense_correlation_batch_container_v1.h */
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
//  Implementation of PCA Correlation algorithm container.
//--
*/

#ifndef __PCA_DENSE_CORRELATION_BATCH_CONTAINER_V1_H__
#define __PCA_DENSE_CORRELATION_BATCH_CONTAINER_V1_H__

#include "kernel.h"
#include "pca/inner/pca_batch_v1.h"
#include "pca_dense_correlation_batch_kernel.h"

namespace daal
{
namespace algorithms
{
namespace pca
{
namespace interface1
{
template <typename algorithmFPType, CpuType cpu>
BatchContainer<algorithmFPType, correlationDense, cpu>::BatchContainer(daal::services::Environment::env * daalEnv)
{
    __DAAL_INITIALIZE_KERNELS(internal::PCACorrelationKernel, batch, algorithmFPType);
}

template <typename algorithmFPType, CpuType cpu>
BatchContainer<algorithmFPType, correlationDense, cpu>::~BatchContainer()
{
    __DAAL_DEINITIALIZE_KERNELS();
}

template <typename algorithmFPType, CpuType cpu>
services::Status BatchContainer<algorithmFPType, correlationDense, cpu>::compute()
{
    Input * input                     = static_cast<Input *>(_in);
    Result * result                   = static_cast<Result *>(_res);

    interface1::BatchParameter<algorithmFPType, correlationDense> * parameter =
        static_cast<interface1::BatchParameter<algorithmFPType, correlationDense> *>(_par);

    services::Environment::env & env = *_env;

    data_management::NumericTablePtr data         = input->get(pca::data);
    data_management::NumericTablePtr eigenvectors = result->get(pca::eigenvectors);
    data_management::NumericTablePtr eigenvalues  = result->get(pca::eigenvalues);

    parameter->covariance->input.set(covariance::data, data);

    __DAAL_CALL_KERNEL(env, internal::PCACorrelationKernel, __DAAL_KERNEL_ARGUMENTS(batch, algorithmFPType), compute, input->isCorrelation(), *data,
                       parameter->covariance.get(), *eigenvectors, *eigenvalues);
}

} // namespace interface1
} // namespace pca
} // namespace algorithms
} // namespace daal

#endif
