#pragma once
namespace dae
{
	class Observer;

	class Subject
	{
	public:
		Subject();
		~Subject();
		void AddObserver(std::shared_ptr<Observer>& observer);
		void RemoveObserver(std::shared_ptr<Observer>& observer);
		void Notify(/*event*/);
	private:
		std::vector<Observer> m_Observers;
	};
}

