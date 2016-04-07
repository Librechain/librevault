/* Copyright (C) 2015 Alexander Shishenko <GamePad64@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "DiscoveryService.h"
#include "folder/p2p/P2PProvider.h"
#include "folder/p2p/WSClient.h"
#include "Client.h"

namespace librevault {

DiscoveryService::DiscoveryService(Client& client) : Loggable(client), client_(client) {}

void DiscoveryService::add_node(const url& node_url, std::shared_ptr<FolderGroup> group_ptr) {
	client_.p2p_provider()->ws_client()->connect(node_url, group_ptr);
}

void DiscoveryService::add_node(const tcp_endpoint& node_endpoint, std::shared_ptr<FolderGroup> group_ptr) {
	client_.p2p_provider()->ws_client()->connect(node_endpoint, group_ptr);
}

void DiscoveryService::add_node(const tcp_endpoint& node_endpoint, const blob& pubkey, std::shared_ptr<FolderGroup> group_ptr) {
	client_.p2p_provider()->ws_client()->connect(node_endpoint, pubkey, group_ptr);
}

} /* namespace librevault */