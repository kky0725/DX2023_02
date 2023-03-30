#pragma once
class SoundManager
{
private:
	SoundManager();
	~SoundManager() {};
public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new SoundManager();
	}

	static void Delete()
	{
		if (_instance != nullptr)
		{
			delete _instance;
			_instance = nullptr;
		}
	}

	static SoundManager* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;
		return nullptr;
	}

	void PAtkSound() { cout << _playerAtkSound << endl; }
	void KAtkSound() {cout<< _knightAtkSound << endl; }
	void MAtkSound() {cout<< _mageAtkSound << endl; }
	void AAtkSound() {cout<< _archerAtkSound << endl; }
	void MoAtkSound() {cout<< _monsterAtkSound << endl; }

	void CrePSound() {cout<< _createPlayerSound << endl; }
	void CreKSound() {cout<< _createKinghtSound << endl; }
	void CreMSound() {cout<< _createMageSound << endl; }
	void CreASound() {cout<< _createArcherSound << endl; }
	void CreMoSound() {cout<< _createMonsterSound << endl; }

	void FireBallSound() { cout << _fireBall << endl; }
	void CriticalSound() { cout << _critical << endl; }
	void MissSound() { cout << _miss << endl; }

private:
	static SoundManager* _instance;

	string _playerAtkSound;
	string _knightAtkSound;
	string _mageAtkSound;
	string _archerAtkSound;
	string _monsterAtkSound;

	string _createPlayerSound;
	string _createKinghtSound;
	string _createMageSound;
	string _createArcherSound;
	string _createMonsterSound;

	string _fireBall;
	string _critical;
	string _miss;

};

