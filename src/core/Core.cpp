#include "Core.hpp"
#include "Log.hpp"

Core::Core() :
	m_running(true)
{
	libtorrent::error_code ec;
	m_session.listen_on(make_pair(6881, 6889), ec);
}

bool Core::isMagnetLink(string url)
{
	string prefix = "magnet:";
	return url.substr(0, prefix.size()) == prefix;
}

bool Core::isRunning()
{
	return m_running;
}

vector<Torrent*> &Core::getTorrents()
{
	return m_torrents;
}

Torrent *Core::addTorrent(string path)
{
	if (path.empty())
		return NULL;
	
	Torrent *t = new Torrent();
	libtorrent::torrent_handle h = m_session.add_torrent(t->getTorrentParams());

	t->setHandle(h);
	m_torrents.push_back(t);

	// TODO: Event polling for magnet update information
	//libtorrent::file_storage fs = info.files();
	//libtorrent::torrent_info info = h.get_torrent_info();

	// An Example For Fetching All Files From Torrent:

	/*unsigned int numFiles = fs.num_files();

	printf("Total Files: %i\n", fs.num_files());
	printf("=========================================\n");

	for (unsigned int i = 0; i < numFiles; ++i)
	{
		libtorrent::file_entry e = fs.at(i);

		printf("Name:\t\t%s\n", e.path.c_str());
		printf("Size:\t\t%i\n", e.size);
		printf("-----------------------------------------\n");
	}

	printf("Total Size:\t%Li\n\n", fs.total_size());

	printf("Downloading data from \"%s\"...\n", path.c_str());*/

	return t;
}

void Core::update()
{
	/*auto iter = std::begin(m_torrents);

	while (iter != std::end(m_torrents))
	{
		auto &t = **iter;

		gt::Event event;

		if (t.pollEvent(event))
		{
			switch (event.type)
			{
				case gt::Event::DownloadCompleted:
					printf("Done!\n");
					iter = m_torrents.erase(iter);
				break;
			}
		}
		else
		{
			++iter;
		}
	}*/
}

void Core::shutdown()
{
	gt::Log::Debug("Shutting down core library...\n");
	m_running = false;
}
