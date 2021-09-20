/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/*!
 * \file np_broadcast_reduce_op_index.cc
 * \brief Implementation of the API of functions in
          src/operator/numpy/np_broadcast_reduce_op_index.cc
 */
#include <mxnet/api_registry.h>
#include <mxnet/runtime/packed_func.h>
#include "../utils.h"
#include "../../../operator/tensor/broadcast_reduce_op.h"

namespace mxnet {

MXNET_REGISTER_API("_npi.argmax")
    .set_body([](runtime::MXNetArgs args, runtime::MXNetRetValue* ret) {
      using namespace runtime;
      const nnvm::Op* op = Op::Get("_npi_argmax");
      nnvm::NodeAttrs attrs;
      op::ReduceAxisParam param;
      // param.axis
      if (args[1].type_code() == kNull) {
        param.axis = dmlc::nullopt;
      } else {
        param.axis = args[1].operator int();
      }
      // param.keepdims
      param.keepdims = args[2].operator bool();

      attrs.parsed = param;
      attrs.op     = op;
      SetAttrDict<op::ReduceAxisParam>(&attrs);
      // inputs
      NDArray* inputs[] = {args[0].operator mxnet::NDArray*()};
      int num_inputs    = 1;
      // outputs
      NDArray* out      = args[3].operator mxnet::NDArray*();
      NDArray** outputs = out == nullptr ? nullptr : &out;
      int num_outputs   = out != nullptr;
      auto ndoutputs    = Invoke(op, &attrs, num_inputs, inputs, &num_outputs, outputs);
      if (out) {
        *ret = PythonArg(3);
      } else {
        *ret = reinterpret_cast<mxnet::NDArray*>(ndoutputs[0]);
      }
    });

MXNET_REGISTER_API("_npi.argmin")
    .set_body([](runtime::MXNetArgs args, runtime::MXNetRetValue* ret) {
      using namespace runtime;
      const nnvm::Op* op = Op::Get("_npi_argmin");
      nnvm::NodeAttrs attrs;
      op::ReduceAxisParam param;
      // param.axis
      if (args[1].type_code() == kNull) {
        param.axis = dmlc::nullopt;
      } else {
        param.axis = args[1].operator int();
      }
      // param.keepdims
      param.keepdims = args[2].operator bool();

      attrs.parsed = param;
      attrs.op     = op;
      SetAttrDict<op::ReduceAxisParam>(&attrs);
      // inputs
      NDArray* inputs[] = {args[0].operator mxnet::NDArray*()};
      int num_inputs    = 1;
      // outputs
      NDArray* out      = args[3].operator mxnet::NDArray*();
      NDArray** outputs = out == nullptr ? nullptr : &out;
      int num_outputs   = out != nullptr;
      auto ndoutputs    = Invoke(op, &attrs, num_inputs, inputs, &num_outputs, outputs);
      if (out) {
        *ret = PythonArg(3);
      } else {
        *ret = reinterpret_cast<mxnet::NDArray*>(ndoutputs[0]);
      }
    });

}  // namespace mxnet
