// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/main/protos/camera_server/camera_server.proto)

#pragma once

#include <array>
#include <cmath>
#include <functional>
#include <limits>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "server_plugin_base.h"

#include "handle.h"

namespace mavsdk {

class ServerComponent;
class CameraServerImpl;

/**
 * @brief Provides handling of camera trigger commands.
 */
class CameraServer : public ServerPluginBase {
public:
    /**
     * @brief Constructor. Creates the plugin for a ServerComponent instance.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto camera_server = CameraServer(server_component);
     *     ```
     *
     * @param server_component The ServerComponent instance associated with this server plugin.
     */
    explicit CameraServer(std::shared_ptr<ServerComponent> server_component);

    /**
     * @brief Destructor (internal use only).
     */
    ~CameraServer() override;

    /**
     * @brief Possible feedback results for camera respond command.
     */
    enum class CameraFeedback {
        Unknown, /**< @brief Unknown. */
        Ok, /**< @brief Ok. */
        Busy, /**< @brief Busy. */
        Failed, /**< @brief Failed. */
    };

    /**
     * @brief Stream operator to print information about a `CameraServer::CameraFeedback`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, CameraServer::CameraFeedback const& camera_feedback);

    /**
     * @brief Camera mode type.
     */
    enum class Mode {
        Unknown, /**< @brief Unknown mode. */
        Photo, /**< @brief Photo mode. */
        Video, /**< @brief Video mode. */
    };

    /**
     * @brief Stream operator to print information about a `CameraServer::Mode`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, CameraServer::Mode const& mode);

    /**
     * @brief Type to represent a camera information.
     */
    struct Information {
        std::string vendor_name{}; /**< @brief Name of the camera vendor */
        std::string model_name{}; /**< @brief Name of the camera model */
        std::string firmware_version{}; /**< @brief Camera firmware version in
                                           major[.minor[.patch[.dev]]] format */
        float focal_length_mm{}; /**< @brief Focal length */
        float horizontal_sensor_size_mm{}; /**< @brief Horizontal sensor size */
        float vertical_sensor_size_mm{}; /**< @brief Vertical sensor size */
        uint32_t horizontal_resolution_px{}; /**< @brief Horizontal image resolution in pixels */
        uint32_t vertical_resolution_px{}; /**< @brief Vertical image resolution in pixels */
        uint32_t lens_id{}; /**< @brief Lens ID */
        uint32_t
            definition_file_version{}; /**< @brief Camera definition file version (iteration) */
        std::string
            definition_file_uri{}; /**< @brief Camera definition URI (http or mavlink ftp) */
    };

    /**
     * @brief Equal operator to compare two `CameraServer::Information` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const CameraServer::Information& lhs, const CameraServer::Information& rhs);

    /**
     * @brief Stream operator to print information about a `CameraServer::Information`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, CameraServer::Information const& information);

    /**
     * @brief Type to represent video streaming settings
     */
    struct VideoStreaming {
        bool has_rtsp_server{}; /**< @brief True if the capture was successful */
        std::string rtsp_uri{}; /**< @brief RTSP URI (e.g. rtsp://192.168.1.42:8554/live) */
    };

    /**
     * @brief Equal operator to compare two `CameraServer::VideoStreaming` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const CameraServer::VideoStreaming& lhs, const CameraServer::VideoStreaming& rhs);

    /**
     * @brief Stream operator to print information about a `CameraServer::VideoStreaming`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, CameraServer::VideoStreaming const& video_streaming);

    /**
     * @brief Position type in global coordinates.
     */
    struct Position {
        double latitude_deg{}; /**< @brief Latitude in degrees (range: -90 to +90) */
        double longitude_deg{}; /**< @brief Longitude in degrees (range: -180 to +180) */
        float absolute_altitude_m{}; /**< @brief Altitude AMSL (above mean sea level) in metres */
        float relative_altitude_m{}; /**< @brief Altitude relative to takeoff altitude in metres */
    };

    /**
     * @brief Equal operator to compare two `CameraServer::Position` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const CameraServer::Position& lhs, const CameraServer::Position& rhs);

    /**
     * @brief Stream operator to print information about a `CameraServer::Position`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, CameraServer::Position const& position);

    /**
     * @brief Quaternion type.
     *
     * All rotations and axis systems follow the right-hand rule.
     * The Hamilton quaternion product definition is used.
     * A zero-rotation quaternion is represented by (1,0,0,0).
     * The quaternion could also be written as w + xi + yj + zk.
     *
     * For more info see: https://en.wikipedia.org/wiki/Quaternion
     */
    struct Quaternion {
        float w{}; /**< @brief Quaternion entry 0, also denoted as a */
        float x{}; /**< @brief Quaternion entry 1, also denoted as b */
        float y{}; /**< @brief Quaternion entry 2, also denoted as c */
        float z{}; /**< @brief Quaternion entry 3, also denoted as d */
    };

    /**
     * @brief Equal operator to compare two `CameraServer::Quaternion` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const CameraServer::Quaternion& lhs, const CameraServer::Quaternion& rhs);

    /**
     * @brief Stream operator to print information about a `CameraServer::Quaternion`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, CameraServer::Quaternion const& quaternion);

    /**
     * @brief Information about a picture just captured.
     */
    struct CaptureInfo {
        Position position{}; /**< @brief Location where the picture was taken */
        Quaternion attitude_quaternion{}; /**< @brief Attitude of the camera when the picture was
                                             taken (quaternion) */
        uint64_t time_utc_us{}; /**< @brief Timestamp in UTC (since UNIX epoch) in microseconds */
        bool is_success{}; /**< @brief True if the capture was successful */
        int32_t index{}; /**< @brief Index from TakePhotoResponse */
        std::string file_url{}; /**< @brief Download URL of this image */
    };

    /**
     * @brief Equal operator to compare two `CameraServer::CaptureInfo` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const CameraServer::CaptureInfo& lhs, const CameraServer::CaptureInfo& rhs);

    /**
     * @brief Stream operator to print information about a `CameraServer::CaptureInfo`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, CameraServer::CaptureInfo const& capture_info);

    /**
     * @brief Possible results returned for action requests.
     */
    enum class Result {
        Unknown, /**< @brief Unknown result. */
        Success, /**< @brief Command executed successfully. */
        InProgress, /**< @brief Command in progress. */
        Busy, /**< @brief Camera is busy and rejected command. */
        Denied, /**< @brief Camera denied the command. */
        Error, /**< @brief An error has occurred while executing the command. */
        Timeout, /**< @brief Command timed out. */
        WrongArgument, /**< @brief Command has wrong argument(s). */
        NoSystem, /**< @brief No system connected. */
    };

    /**
     * @brief Stream operator to print information about a `CameraServer::Result`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, CameraServer::Result const& result);

    /**
     * @brief Information about the camera storage.
     */
    struct StorageInformation {
        /**
         * @brief Storage status type.
         */
        enum class StorageStatus {
            NotAvailable, /**< @brief Storage not available. */
            Unformatted, /**< @brief Storage is not formatted (i.e. has no recognized file system).
                          */
            Formatted, /**< @brief Storage is formatted (i.e. has recognized a file system). */
            NotSupported, /**< @brief Storage status is not supported. */
        };

        /**
         * @brief Stream operator to print information about a `CameraServer::StorageStatus`.
         *
         * @return A reference to the stream.
         */
        friend std::ostream& operator<<(
            std::ostream& str,
            CameraServer::StorageInformation::StorageStatus const& storage_status);

        /**
         * @brief Storage type.
         */
        enum class StorageType {
            Unknown, /**< @brief Storage type unknown. */
            UsbStick, /**< @brief Storage type USB stick. */
            Sd, /**< @brief Storage type SD card. */
            Microsd, /**< @brief Storage type MicroSD card. */
            Hd, /**< @brief Storage type HD mass storage. */
            Other, /**< @brief Storage type other, not listed. */
        };

        /**
         * @brief Stream operator to print information about a `CameraServer::StorageType`.
         *
         * @return A reference to the stream.
         */
        friend std::ostream& operator<<(
            std::ostream& str, CameraServer::StorageInformation::StorageType const& storage_type);

        float used_storage_mib{}; /**< @brief Used storage (in MiB) */
        float available_storage_mib{}; /**< @brief Available storage (in MiB) */
        float total_storage_mib{}; /**< @brief Total storage (in MiB) */
        StorageStatus storage_status{}; /**< @brief Storage status */
        uint32_t storage_id{}; /**< @brief Storage ID starting at 1 */
        StorageType storage_type{}; /**< @brief Storage type */
        float read_speed_mib_s{}; /**< @brief Read speed [MiB/s] */
        float write_speed_mib_s{}; /**< @brief Write speed [MiB/s] */
    };

    /**
     * @brief Equal operator to compare two `CameraServer::StorageInformation` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(
        const CameraServer::StorageInformation& lhs, const CameraServer::StorageInformation& rhs);

    /**
     * @brief Stream operator to print information about a `CameraServer::StorageInformation`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, CameraServer::StorageInformation const& storage_information);

    /**
     * @brief
     */
    struct CaptureStatus {
        /**
         * @brief
         */
        enum class ImageStatus {
            Idle, /**< @brief idle. */
            CaptureInProgress, /**< @brief capture in progress. */
            IntervalIdle, /**< @brief interval set but idle. */
            IntervalInProgress, /**< @brief interval set and capture in progress). */
        };

        /**
         * @brief Stream operator to print information about a `CameraServer::ImageStatus`.
         *
         * @return A reference to the stream.
         */
        friend std::ostream&
        operator<<(std::ostream& str, CameraServer::CaptureStatus::ImageStatus const& image_status);

        /**
         * @brief
         */
        enum class VideoStatus {
            Idle, /**< @brief idle. */
            CaptureInProgress, /**< @brief capture in progress. */
        };

        /**
         * @brief Stream operator to print information about a `CameraServer::VideoStatus`.
         *
         * @return A reference to the stream.
         */
        friend std::ostream&
        operator<<(std::ostream& str, CameraServer::CaptureStatus::VideoStatus const& video_status);

        float image_interval_s{}; /**< @brief Image capture interval (in s) */
        float recording_time_s{}; /**< @brief Elapsed time since recording started (in s) */
        float available_capacity_mib{}; /**< @brief Available storage capacity. (in MiB) */
        ImageStatus image_status{}; /**< @brief Current status of image capturing */
        VideoStatus video_status{}; /**< @brief Current status of video capturing */
        int32_t image_count{}; /**< @brief Total number of images captured ('forever', or until
                                  reset using MAV_CMD_STORAGE_FORMAT) */
    };

    /**
     * @brief Equal operator to compare two `CameraServer::CaptureStatus` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const CameraServer::CaptureStatus& lhs, const CameraServer::CaptureStatus& rhs);

    /**
     * @brief Stream operator to print information about a `CameraServer::CaptureStatus`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, CameraServer::CaptureStatus const& capture_status);

    /**
     * @brief Callback type for asynchronous CameraServer calls.
     */
    using ResultCallback = std::function<void(Result)>;

    /**
     * @brief Sets the camera information. This must be called as soon as the camera server is
     * created.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result set_information(Information information) const;

    /**
     * @brief Sets video streaming settings.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result set_video_streaming(VideoStreaming video_streaming) const;

    /**
     * @brief Sets image capture in progress status flags. This should be set to true when the
     * camera is busy taking a photo and false when it is done.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result set_in_progress(bool in_progress) const;

    /**
     * @brief Callback type for subscribe_take_photo.
     */
    using TakePhotoCallback = std::function<void(int32_t)>;

    /**
     * @brief Handle type for subscribe_take_photo.
     */
    using TakePhotoHandle = Handle<int32_t>;

    /**
     * @brief Subscribe to image capture requests. Each request received should respond to using
     * RespondTakePhoto.
     */
    TakePhotoHandle subscribe_take_photo(const TakePhotoCallback& callback);

    /**
     * @brief Unsubscribe from subscribe_take_photo
     */
    void unsubscribe_take_photo(TakePhotoHandle handle);

    /**
     * @brief Respond to an image capture request from SubscribeTakePhoto.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result respond_take_photo(CameraFeedback take_photo_feedback, CaptureInfo capture_info) const;

    /**
     * @brief Callback type for subscribe_start_video.
     */
    using StartVideoCallback = std::function<void(int32_t)>;

    /**
     * @brief Handle type for subscribe_start_video.
     */
    using StartVideoHandle = Handle<int32_t>;

    /**
     * @brief Subscribe to start video requests. Each request received should respond to using
     * RespondStartVideo
     */
    StartVideoHandle subscribe_start_video(const StartVideoCallback& callback);

    /**
     * @brief Unsubscribe from subscribe_start_video
     */
    void unsubscribe_start_video(StartVideoHandle handle);

    /**
     * @brief Subscribe to stop video requests. Each request received should respond using
     * StopVideoResponse
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result respond_start_video(CameraFeedback start_video_feedback) const;

    /**
     * @brief Callback type for subscribe_stop_video.
     */
    using StopVideoCallback = std::function<void(int32_t)>;

    /**
     * @brief Handle type for subscribe_stop_video.
     */
    using StopVideoHandle = Handle<int32_t>;

    /**
     * @brief Subscribe to stop video requests. Each request received should response to using
     * RespondStopVideo
     */
    StopVideoHandle subscribe_stop_video(const StopVideoCallback& callback);

    /**
     * @brief Unsubscribe from subscribe_stop_video
     */
    void unsubscribe_stop_video(StopVideoHandle handle);

    /**
     * @brief Respond to stop video request from SubscribeStopVideo.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result respond_stop_video(CameraFeedback stop_video_feedback) const;

    /**
     * @brief Callback type for subscribe_start_video_streaming.
     */
    using StartVideoStreamingCallback = std::function<void(int32_t)>;

    /**
     * @brief Handle type for subscribe_start_video_streaming.
     */
    using StartVideoStreamingHandle = Handle<int32_t>;

    /**
     * @brief Subscribe to start video streaming requests. Each request received should response to
     * using RespondStartVideoStreaming
     */
    StartVideoStreamingHandle
    subscribe_start_video_streaming(const StartVideoStreamingCallback& callback);

    /**
     * @brief Unsubscribe from subscribe_start_video_streaming
     */
    void unsubscribe_start_video_streaming(StartVideoStreamingHandle handle);

    /**
     * @brief Respond to start video streaming from SubscribeStartVideoStreaming.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result respond_start_video_streaming(CameraFeedback start_video_streaming_feedback) const;

    /**
     * @brief Callback type for subscribe_stop_video_streaming.
     */
    using StopVideoStreamingCallback = std::function<void(int32_t)>;

    /**
     * @brief Handle type for subscribe_stop_video_streaming.
     */
    using StopVideoStreamingHandle = Handle<int32_t>;

    /**
     * @brief Subscribe to stop video streaming requests. Each request received should response to
     * using RespondStopVideoStreaming
     */
    StopVideoStreamingHandle
    subscribe_stop_video_streaming(const StopVideoStreamingCallback& callback);

    /**
     * @brief Unsubscribe from subscribe_stop_video_streaming
     */
    void unsubscribe_stop_video_streaming(StopVideoStreamingHandle handle);

    /**
     * @brief Respond to stop video streaming from SubscribeStopVideoStreaming.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result respond_stop_video_streaming(CameraFeedback stop_video_streaming_feedback) const;

    /**
     * @brief Callback type for subscribe_set_mode.
     */
    using SetModeCallback = std::function<void(Mode)>;

    /**
     * @brief Handle type for subscribe_set_mode.
     */
    using SetModeHandle = Handle<Mode>;

    /**
     * @brief Subscribe to set camera mode requests. Each request received should response to using
     * RespondSetMode
     */
    SetModeHandle subscribe_set_mode(const SetModeCallback& callback);

    /**
     * @brief Unsubscribe from subscribe_set_mode
     */
    void unsubscribe_set_mode(SetModeHandle handle);

    /**
     * @brief Respond to set camera mode from SubscribeSetMode.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result respond_set_mode(CameraFeedback set_mode_feedback) const;

    /**
     * @brief Callback type for subscribe_storage_information.
     */
    using StorageInformationCallback = std::function<void(int32_t)>;

    /**
     * @brief Handle type for subscribe_storage_information.
     */
    using StorageInformationHandle = Handle<int32_t>;

    /**
     * @brief Subscribe to camera storage information requests. Each request received should
     * response to using RespondStorageInformation
     */
    StorageInformationHandle
    subscribe_storage_information(const StorageInformationCallback& callback);

    /**
     * @brief Unsubscribe from subscribe_storage_information
     */
    void unsubscribe_storage_information(StorageInformationHandle handle);

    /**
     * @brief Respond to camera storage information from SubscribeStorageInformation.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result respond_storage_information(
        CameraFeedback storage_information_feedback, StorageInformation storage_information) const;

    /**
     * @brief Callback type for subscribe_capture_status.
     */
    using CaptureStatusCallback = std::function<void(int32_t)>;

    /**
     * @brief Handle type for subscribe_capture_status.
     */
    using CaptureStatusHandle = Handle<int32_t>;

    /**
     * @brief Subscribe to camera capture status requests. Each request received should response to
     * using RespondCaptureStatus
     */
    CaptureStatusHandle subscribe_capture_status(const CaptureStatusCallback& callback);

    /**
     * @brief Unsubscribe from subscribe_capture_status
     */
    void unsubscribe_capture_status(CaptureStatusHandle handle);

    /**
     * @brief Respond to camera capture status from SubscribeCaptureStatus.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result respond_capture_status(
        CameraFeedback capture_status_feedback, CaptureStatus capture_status) const;

    /**
     * @brief Callback type for subscribe_format_storage.
     */
    using FormatStorageCallback = std::function<void(int32_t)>;

    /**
     * @brief Handle type for subscribe_format_storage.
     */
    using FormatStorageHandle = Handle<int32_t>;

    /**
     * @brief Subscribe to format storage requests. Each request received should response to using
     * RespondFormatStorage
     */
    FormatStorageHandle subscribe_format_storage(const FormatStorageCallback& callback);

    /**
     * @brief Unsubscribe from subscribe_format_storage
     */
    void unsubscribe_format_storage(FormatStorageHandle handle);

    /**
     * @brief Respond to format storage from SubscribeFormatStorage.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result respond_format_storage(CameraFeedback format_storage_feedback) const;

    /**
     * @brief Callback type for subscribe_reset_settings.
     */
    using ResetSettingsCallback = std::function<void(int32_t)>;

    /**
     * @brief Handle type for subscribe_reset_settings.
     */
    using ResetSettingsHandle = Handle<int32_t>;

    /**
     * @brief Subscribe to reset settings requests. Each request received should response to using
     * RespondResetSettings
     */
    ResetSettingsHandle subscribe_reset_settings(const ResetSettingsCallback& callback);

    /**
     * @brief Unsubscribe from subscribe_reset_settings
     */
    void unsubscribe_reset_settings(ResetSettingsHandle handle);

    /**
     * @brief Respond to reset settings from SubscribeResetSettings.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result respond_reset_settings(CameraFeedback reset_settings_feedback) const;

    /**
     * @brief Copy constructor.
     */
    CameraServer(const CameraServer& other);

    /**
     * @brief Equality operator (object is not copyable).
     */
    const CameraServer& operator=(const CameraServer&) = delete;

private:
    /** @private Underlying implementation, set at instantiation */
    std::unique_ptr<CameraServerImpl> _impl;
};

} // namespace mavsdk