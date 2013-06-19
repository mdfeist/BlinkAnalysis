#pragma once
class RecorderManager
{
public:
	static RecorderManager* getInstance() {
		if(!m_pInstance) m_pInstance = new RecorderManager();
		return m_pInstance;
	}

protected:
	RecorderManager(void);
	~RecorderManager(void);
private:
	RecorderManager(RecorderManager const&);
	RecorderManager& operator=(RecorderManager const&);

	static RecorderManager* m_pInstance;
};

