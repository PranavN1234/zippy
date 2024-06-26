// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: zippy.proto

#include "zippy.pb.h"
#include "zippy.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace zippy {

static const char* Zippy_method_names[] = {
  "/zippy.Zippy/ExecuteCommand",
  "/zippy.Zippy/GenerateUUID",
};

std::unique_ptr< Zippy::Stub> Zippy::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Zippy::Stub> stub(new Zippy::Stub(channel, options));
  return stub;
}

Zippy::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_ExecuteCommand_(Zippy_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GenerateUUID_(Zippy_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status Zippy::Stub::ExecuteCommand(::grpc::ClientContext* context, const ::zippy::CommandRequest& request, ::zippy::CommandResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::zippy::CommandRequest, ::zippy::CommandResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_ExecuteCommand_, context, request, response);
}

void Zippy::Stub::async::ExecuteCommand(::grpc::ClientContext* context, const ::zippy::CommandRequest* request, ::zippy::CommandResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::zippy::CommandRequest, ::zippy::CommandResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_ExecuteCommand_, context, request, response, std::move(f));
}

void Zippy::Stub::async::ExecuteCommand(::grpc::ClientContext* context, const ::zippy::CommandRequest* request, ::zippy::CommandResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_ExecuteCommand_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::zippy::CommandResponse>* Zippy::Stub::PrepareAsyncExecuteCommandRaw(::grpc::ClientContext* context, const ::zippy::CommandRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::zippy::CommandResponse, ::zippy::CommandRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_ExecuteCommand_, context, request);
}

::grpc::ClientAsyncResponseReader< ::zippy::CommandResponse>* Zippy::Stub::AsyncExecuteCommandRaw(::grpc::ClientContext* context, const ::zippy::CommandRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncExecuteCommandRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status Zippy::Stub::GenerateUUID(::grpc::ClientContext* context, const ::zippy::UUIDRequest& request, ::zippy::UUIDResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::zippy::UUIDRequest, ::zippy::UUIDResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GenerateUUID_, context, request, response);
}

void Zippy::Stub::async::GenerateUUID(::grpc::ClientContext* context, const ::zippy::UUIDRequest* request, ::zippy::UUIDResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::zippy::UUIDRequest, ::zippy::UUIDResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GenerateUUID_, context, request, response, std::move(f));
}

void Zippy::Stub::async::GenerateUUID(::grpc::ClientContext* context, const ::zippy::UUIDRequest* request, ::zippy::UUIDResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GenerateUUID_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::zippy::UUIDResponse>* Zippy::Stub::PrepareAsyncGenerateUUIDRaw(::grpc::ClientContext* context, const ::zippy::UUIDRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::zippy::UUIDResponse, ::zippy::UUIDRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GenerateUUID_, context, request);
}

::grpc::ClientAsyncResponseReader< ::zippy::UUIDResponse>* Zippy::Stub::AsyncGenerateUUIDRaw(::grpc::ClientContext* context, const ::zippy::UUIDRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGenerateUUIDRaw(context, request, cq);
  result->StartCall();
  return result;
}

Zippy::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Zippy_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Zippy::Service, ::zippy::CommandRequest, ::zippy::CommandResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Zippy::Service* service,
             ::grpc::ServerContext* ctx,
             const ::zippy::CommandRequest* req,
             ::zippy::CommandResponse* resp) {
               return service->ExecuteCommand(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Zippy_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Zippy::Service, ::zippy::UUIDRequest, ::zippy::UUIDResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Zippy::Service* service,
             ::grpc::ServerContext* ctx,
             const ::zippy::UUIDRequest* req,
             ::zippy::UUIDResponse* resp) {
               return service->GenerateUUID(ctx, req, resp);
             }, this)));
}

Zippy::Service::~Service() {
}

::grpc::Status Zippy::Service::ExecuteCommand(::grpc::ServerContext* context, const ::zippy::CommandRequest* request, ::zippy::CommandResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Zippy::Service::GenerateUUID(::grpc::ServerContext* context, const ::zippy::UUIDRequest* request, ::zippy::UUIDResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace zippy

