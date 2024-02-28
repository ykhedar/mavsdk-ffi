// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/ftp/ftp.proto)

#include <iomanip>

#include "ftp_impl.h"
#include "plugins/ftp/ftp.h"

namespace mavsdk {

using ProgressData = Ftp::ProgressData;

Ftp::Ftp(System& system) : PluginBase(), _impl{std::make_unique<FtpImpl>(system)} {}

Ftp::Ftp(std::shared_ptr<System> system) : PluginBase(), _impl{std::make_unique<FtpImpl>(system)} {}

Ftp::~Ftp() {}

void Ftp::download_async(
    std::string remote_file_path,
    std::string local_dir,
    bool use_burst,
    const DownloadCallback& callback)
{
    _impl->download_async(remote_file_path, local_dir, use_burst, callback);
}

void Ftp::upload_async(
    std::string local_file_path, std::string remote_dir, const UploadCallback& callback)
{
    _impl->upload_async(local_file_path, remote_dir, callback);
}

void Ftp::list_directory_async(std::string remote_dir, const ListDirectoryCallback callback)
{
    _impl->list_directory_async(remote_dir, callback);
}

std::pair<Ftp::Result, std::vector<std::string>> Ftp::list_directory(std::string remote_dir) const
{
    return _impl->list_directory(remote_dir);
}

void Ftp::create_directory_async(std::string remote_dir, const ResultCallback callback)
{
    _impl->create_directory_async(remote_dir, callback);
}

Ftp::Result Ftp::create_directory(std::string remote_dir) const
{
    return _impl->create_directory(remote_dir);
}

void Ftp::remove_directory_async(std::string remote_dir, const ResultCallback callback)
{
    _impl->remove_directory_async(remote_dir, callback);
}

Ftp::Result Ftp::remove_directory(std::string remote_dir) const
{
    return _impl->remove_directory(remote_dir);
}

void Ftp::remove_file_async(std::string remote_file_path, const ResultCallback callback)
{
    _impl->remove_file_async(remote_file_path, callback);
}

Ftp::Result Ftp::remove_file(std::string remote_file_path) const
{
    return _impl->remove_file(remote_file_path);
}

void Ftp::rename_async(
    std::string remote_from_path, std::string remote_to_path, const ResultCallback callback)
{
    _impl->rename_async(remote_from_path, remote_to_path, callback);
}

Ftp::Result Ftp::rename(std::string remote_from_path, std::string remote_to_path) const
{
    return _impl->rename(remote_from_path, remote_to_path);
}

void Ftp::are_files_identical_async(
    std::string local_file_path,
    std::string remote_file_path,
    const AreFilesIdenticalCallback callback)
{
    _impl->are_files_identical_async(local_file_path, remote_file_path, callback);
}

std::pair<Ftp::Result, bool>
Ftp::are_files_identical(std::string local_file_path, std::string remote_file_path) const
{
    return _impl->are_files_identical(local_file_path, remote_file_path);
}

Ftp::Result Ftp::set_target_compid(uint32_t compid) const
{
    return _impl->set_target_compid(compid);
}

bool operator==(const Ftp::ProgressData& lhs, const Ftp::ProgressData& rhs)
{
    return (rhs.bytes_transferred == lhs.bytes_transferred) && (rhs.total_bytes == lhs.total_bytes);
}

std::ostream& operator<<(std::ostream& str, Ftp::ProgressData const& progress_data)
{
    str << std::setprecision(15);
    str << "progress_data:" << '\n' << "{\n";
    str << "    bytes_transferred: " << progress_data.bytes_transferred << '\n';
    str << "    total_bytes: " << progress_data.total_bytes << '\n';
    str << '}';
    return str;
}

std::ostream& operator<<(std::ostream& str, Ftp::Result const& result)
{
    switch (result) {
        case Ftp::Result::Unknown:
            return str << "Unknown";
        case Ftp::Result::Success:
            return str << "Success";
        case Ftp::Result::Next:
            return str << "Next";
        case Ftp::Result::Timeout:
            return str << "Timeout";
        case Ftp::Result::Busy:
            return str << "Busy";
        case Ftp::Result::FileIoError:
            return str << "File Io Error";
        case Ftp::Result::FileExists:
            return str << "File Exists";
        case Ftp::Result::FileDoesNotExist:
            return str << "File Does Not Exist";
        case Ftp::Result::FileProtected:
            return str << "File Protected";
        case Ftp::Result::InvalidParameter:
            return str << "Invalid Parameter";
        case Ftp::Result::Unsupported:
            return str << "Unsupported";
        case Ftp::Result::ProtocolError:
            return str << "Protocol Error";
        case Ftp::Result::NoSystem:
            return str << "No System";
        default:
            return str << "Unknown";
    }
}

} // namespace mavsdk