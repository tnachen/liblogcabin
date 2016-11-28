#include "liblogcabin/Core/Config.h"
#include "liblogcabin/Core/Debug.h"
#include "liblogcabin/Raft/RaftConsensus.h"

namespace LibLogCabin {
namespace Raft {

using namespace LibLogCabin::Core;
using namespace LibLogCabin::Storage;

class SimpleServer {
public:
  SimpleServer(Config& config, uint64_t serverId, Snapshot::FileFactory* factory);
  ~SimpleServer();
  void start();
  void exit();
  bool verifyCallbackData(int lastData);
  bool setConfiguration(uint64_t lastServerId);
  bool pushData(const std::string& data);
  bool takeSnapshot();
  void readSnapshot();

private:
  RaftConsensus raft;
  uint64_t serverId;
  std::vector<std::string> data;
};
