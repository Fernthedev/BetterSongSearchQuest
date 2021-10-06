#include "main.hpp"

#include "UI/FlowCoordinators/BetterSongSearchFlowCoordinator.hpp"

#include "System/Action.hpp"
#include "System/Action_1.hpp"
#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"

#include "questui/shared/BeatSaberUI.hpp"
#include "questui/shared/QuestUI.hpp"
using namespace QuestUI;

DEFINE_TYPE(BetterSongSearch::UI::FlowCoordinators, BetterSongSearchFlowCoordinator);

void BetterSongSearch::UI::FlowCoordinators::BetterSongSearchFlowCoordinator::Awake() {
    fcInstance = this;
    if (!SongListViewController) {
        SongListViewController = BeatSaberUI::CreateViewController<ViewControllers::SongListViewController*>();
    }
    if (!FilterViewController) {
        FilterViewController = BeatSaberUI::CreateViewController<ViewControllers::FilterViewController*>();
    }
    if (!DownloadHistoryViewController) {
        DownloadHistoryViewController = BeatSaberUI::CreateViewController<ViewControllers::DownloadHistoryViewController*>();
    }
}

void BetterSongSearch::UI::FlowCoordinators::BetterSongSearchFlowCoordinator::DidActivate(bool firstActivation, bool addedToHeirarchy, bool screenSystemEnabling) {
    //if (!firstActivation) return;

    SetTitle(il2cpp_utils::newcsstr("Better Song Search"), HMUI::ViewController::AnimationType::In);
    showBackButton = true;
    ProvideInitialViewControllers(SongListViewController, FilterViewController, DownloadHistoryViewController, nullptr, nullptr);
}

void BetterSongSearch::UI::FlowCoordinators::BetterSongSearchFlowCoordinator::BackButtonWasPressed(HMUI::ViewController* topViewController) {
    this->parentFlowCoordinator->DismissFlowCoordinator(this, HMUI::ViewController::AnimationDirection::Horizontal, nullptr, false);
}