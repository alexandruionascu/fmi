#include <bits/stdc++.h>
#define in f
#define out g
#define int64 long long
using namespace std;

ifstream f("videos_worth_spreading.in");
ofstream g("videos_worth_spreading1.out");

const int MAX_SIZE = 10000 + 10;
int videos_count, endpoints_count, req_desc_count;
int cache_servers_count, cache_size;
vector<int> videos;
int data_center_latency[MAX_SIZE];
vector<pair<int, int>> latency[MAX_SIZE];
vector<pair<int, int>> requests[MAX_SIZE];

int64 min(int64 a, int64 b) {
  if (a < b)
    return a;
  return b;
}
void read() {
  in >> videos_count;
  in >> endpoints_count;
  in >> req_desc_count;
  in >> cache_servers_count;
  in >> cache_size;
  int x, y, z;
  for (int i = 1; i <= videos_count; i++) {
    in >> x;
    videos.push_back(x);
  }

  for (int i = 0; i < endpoints_count; i++) {
    in >> data_center_latency[i];
    int caches;
    in >> caches;
    for (int j = 1; j <= caches; j++) {
      in >> x;
      in >> y;
      latency[i].push_back({x, y});
    }
  }

  for (int i = 1; i <= req_desc_count; i++) {
    in >> x;
    in >> y;
    in >> z;
    requests[y].push_back({x, z});
  }
}

int64 check(set<pair<int, int>>& solution) {
  int64 total = 0;
  // for endpoint i
  for (int i = 0; i < endpoints_count; i++) {
    // for each request in endpoint i
    for (auto req : requests[i]) {
      int req_video = req.first;
      int req_count = req.second;

      int64 min_latency = data_center_latency[i] * req_count;
      for (auto l : latency[i]) {
        int cache_id = l.first;
        int cost = l.second;

        if (solution.find({cache_id, req_video}) != solution.end()) {
          min_latency = min(min_latency, cost * req_count);
        }
      }

      total += min_latency;
    }
  }

  return total;
}

void print(set<pair<int, int>>& solution) {
  vector<int> v[MAX_SIZE];
  for (auto sol : solution) {
    v[sol.first].push_back(sol.second);
  }

  int cache_servers = 0;
  for (int i = 0; i < cache_servers_count; i++) {
    if (v[i].size() > 0)
      cache_servers++;
  }
  out << cache_servers << "\n";
  for (int i = 0; i < cache_servers_count; i++) {
    if (v[i].size() > 0) {
      out << i << " ";
      for (auto c : v[i]) {
        out << c << " ";
      }
      out << "\n";
    }
  }
}

set<pair<int, int>> solve() {
  int tries = 1000;
  int max_attempts = 3000;
  set<pair<int, int>> best;
  int64 minn = ((int64)1 << (int64)60);
  for (int i = 1; i <= tries; i++) {
    set<pair<int, int>> current_sol;
    for (int cache = 0; cache < cache_servers_count; cache++) {
      unordered_set<int> selected_videos;
      int remaining_memory = cache_size;
      int attempts = 0;
      while (attempts < max_attempts) {
        int video_id = rand() % videos_count;
        if (selected_videos.find(video_id) == selected_videos.end()) {
          if (remaining_memory >= videos[video_id]) {
            remaining_memory -= videos[video_id];
            selected_videos.insert(video_id);
            current_sol.insert({cache, video_id});
            continue;
          }
        }
        attempts++;
      }
    }

    int64 score = check(current_sol);
    if (score < minn) {
      minn = score;
      best = current_sol;
    }
  }
  print(best);
}

int main() {
  srand(time(NULL));
  read();
  solve();
  cout << endl << "RETURNED 0";
}
